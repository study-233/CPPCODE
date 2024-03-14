#include <iostream>
#include <string>
#include <sstream>
#include <vector>

const int NumType = 0;
const int OperatorType = 1;
const int LeftBracket = 2;
const int RightBracket = 3;
const int ExprType = 4;

class Visitor;
class PrintVistor;
class Token;
class NumToken;
class OperatorToken;
class BracketToken;
class ExprToken;

// 字符串转换为数字
float helpStringToNum(const std::string &text)
{
    float ret;
    std::stringstream ss;
    ss << text;
    ss >> ret;
    return ret;
}

// 用于遍历的访问者接�?
class Visitor
{
    public:
        virtual void apply(Token *token) = 0;
};

// 标识符抽�?
class Token
{
    public:
        const std::string text;     // 原文副本
        const int type;             // 标识符类型，方便动态类型转�?

        virtual void visit(Visitor *visitor);
    protected:
        Token(std::string text, const int type)
            :text(text), type(type) {}

        virtual ~Token() {}
};

// 遍历默认行为：让访问者看到自�?
void Token::visit(Visitor *visitor)
{
    visitor->apply(this);
};

// 数字标识�?
class NumToken : public Token
{
    public:
        const float value;

        NumToken(std::string text)
            :Token(text, NumType)
            ,value(helpStringToNum(text))
        { }
};

// 运算符标识符
class OperatorToken : public Token
{
    public:
        const char op;

        OperatorToken(const char op)
            :Token(std::string(1, op), OperatorType)
            ,op(op) { }
};

// 括号标识�?
class BracketToken : public Token
{
    public:
        BracketToken(const char op)
            :Token(std::string(1, op), op == '(' ? LeftBracket : RightBracket)
        { }
};

// 表达式标识符
class ExprToken : public Token
{
    private:
        NumToken *num;
        OperatorToken *op;
        ExprToken *lhs, *rhs;
        bool bracket;

        float calc() 
        {
            if (op)
            {
                float l(lhs->value), r(rhs->value);
                switch (op->op)
                {
                    case '+': return l + r;
                    case '-': return l - r;
                    case '*': return l * r;
                    case '/': return l / r;
                }
            }
            else
                return num->value;
            return 0;
        }

    public:
        const float value;

        ExprToken(NumToken *num)
            :Token(num->text, ExprType), num(num), 
            op(NULL), lhs(NULL), rhs(NULL), value(calc()) {}

        ExprToken(ExprToken *lhs, OperatorToken *op_, ExprToken *rhs)
            :Token(lhs->text + op_->text + rhs->text, ExprType),
            num(NULL), op(op_), lhs(lhs), rhs(rhs), value(calc()) {}

        ExprToken(BracketToken *lb, ExprToken *expr, BracketToken *rb)
            :Token(lb->text + expr->text + rb->text, ExprType),
            num(NULL), op(NULL), lhs(expr), rhs(NULL),
            value(expr->value) 
        {
            bracket = true;
        }

        virtual void visit(Visitor *visitor)
        {
            if (lhs) lhs->visit(visitor);
            if (rhs) rhs->visit(visitor);
            visitor->apply(this);
        }

        virtual ~ExprToken()
        {
            delete num;
            delete op;
            delete lhs;
            delete rhs;
        }
};

// 打印访问者：输出运算过程
class PrintVistor : public Visitor
{
    private:
        int line;
    public:
        PrintVistor(): line(0) {}

        virtual void apply(Token *token)
        {
            if (token->type == ExprType)
            {
                ExprToken *expr = dynamic_cast<ExprToken *>(token);
                std::cout << '#' << ++line << ": "
                    << token->text << " = ";
                if (expr)
                    std::cout << expr->value;
                else
                    std::cout << "NaN";
                std::cout << std::endl;
            }
        }
};

// 词汇分析，从字符串生成基础标识�?
std::vector<Token *> parse(std::string text)
{
    std::vector<Token *> vec;
    for (int i = 0; i < text.length(); ++i)
    {
        switch (text[i])
        {
            case ' ':
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                vec.push_back(new OperatorToken(text[i]));
                break;
            case '(':
            case ')':
                vec.push_back(new BracketToken(text[i]));
                break;
            default:
            {
                int r;
                for (r = i; r < text.length() && text[r] >= '0' 
                        && text[r] <= '9'; ++r);
                vec.push_back(new NumToken(text.substr(i, r - i)));
                i = r - 1;
            }
        }
    }
    return vec;
}

// 判断是否为运算，且优先级与指定优先级相同
bool is_expr(Token *lhs, Token *op, Token *rhs, bool priority = true)
{
    if (lhs->type != ExprType
            || op->type != OperatorType
            || rhs->type != ExprType)
        return false;
    OperatorToken *_op = dynamic_cast<OperatorToken *>(op);
    return _op && (!priority ^ (_op->op == '*' || _op->op == '/'));
}

// 根据四则运算法则归约标识�?
void compile(std::vector<Token *> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
        if (vec[i]->type == NumType)
        {
            NumToken *num = dynamic_cast<NumToken *>(vec[i]);
            if (num)
                vec[i] = new ExprToken(num);
            else
                vec[i] = new ExprToken(new NumToken("0"));
        }
    while (vec.size() > 1)
    {
        bool flag = false;
        // 归约：expr ::= '(' expr ')'
        for (int i = 0; i < vec.size() - 2; ++i)
        {
            if (vec[i]->type == LeftBracket && vec[i + 2]->type == RightBracket
                    && vec[i + 1]->type == ExprType)
            {
                flag = true;
                ExprToken *expr = new ExprToken(
                        dynamic_cast<BracketToken *>(vec[i]),
                        dynamic_cast<ExprToken *>(vec[i + 1]),
                        dynamic_cast<BracketToken *>(vec[i + 2]));
                vec.erase(vec.begin() + i + 1, vec.begin() + i + 3);
                vec[i] = expr;
            }
            if (flag) break;
        }
        if (flag) continue;
        // 归约：expr ::= expr '*' expr
        // 归约：expr ::= expr '/' expr
        for (int i = 0; i < vec.size() - 2; ++i)
        {
            if (is_expr(vec[i], vec[i + 1], vec[i + 2], true))
            {
                flag = true;
                ExprToken *expr = new ExprToken(
                        dynamic_cast<ExprToken *>(vec[i]),
                        dynamic_cast<OperatorToken *>(vec[i + 1]),
                        dynamic_cast<ExprToken *>(vec[i + 2]));
                vec.erase(vec.begin() + i + 1, vec.begin() + i + 3);
                vec[i] = expr;
            }
            if (flag) break;
        }
        if (flag) continue;
        // 归约：expr ::= expr '+' expr
        // 归约：expr ::= expr '-' expr
        for (int i = 0; i < vec.size() - 2; ++i)
        {
            if (is_expr(vec[i], vec[i + 1], vec[i + 2]))
            {
                if (i > 0 && vec[i - 1]->type == OperatorType
                        && (dynamic_cast<OperatorToken *>(vec[i - 1])->op == '*'
                            || dynamic_cast<OperatorToken *>(vec[i - 1])->op == '/'))
                    continue;
                if (i + 3 < vec.size() && vec[i + 3]->type == OperatorType
                        && (dynamic_cast<OperatorToken *>(vec[i + 3])->op == '*'
                            || dynamic_cast<OperatorToken *>(vec[i + 3])->op == '/'))
                    continue;
                flag = true;
                ExprToken *expr = new ExprToken(
                        dynamic_cast<ExprToken *>(vec[i]),
                        dynamic_cast<OperatorToken *>(vec[i + 1]),
                        dynamic_cast<ExprToken *>(vec[i + 2]));
                vec.erase(vec.begin() + i + 1, vec.begin() + i + 3);
                vec[i] = expr;
            }
            if (flag) break;
        }
        if (!flag) 
        {
            std::cout << "error" << std::endl;
            return ;
        }
    }

    PrintVistor v;
    vec[0]->visit(&v);
}



int main(int argc, char *argv[])
{
    std::string s;
    std::cin >> s;
    std::vector<Token *> vec = parse(s);
    compile(vec);
    return 0;
}