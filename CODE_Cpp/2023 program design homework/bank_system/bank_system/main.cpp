//step6.cpp

#include "date.h"
#include "account.h"
#include "savingaccount.h"
#include "creditaccount.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

    Date date(2008, 11, 1);//起始日期
    vector<Account *> accounts;//创建账户数组，元素个数为0
    char cmd,type;
    int index_, day;
    double amount, credit, rate, fee;
    string id, desc;
    Account* account;
    Date date1, date2;


struct deleter {
    template <class T> void operator () (T* p) { delete p; }
};

void read_cmd(){
    ifstream ifs;
    ifs.open("commands.txt");

    if(!ifs.is_open()){return;}

    while(ifs>>cmd){
        switch (cmd) {
            case 'a'://增加账户
            
                ifs >> type >> id;

                if (type == 's') {
                    ifs >> rate;
                    account = new SavingsAccount(date, id, rate);
                }
                else {
                    ifs >> credit >> rate >> fee;
                    account = new CreditAccount(date, id, credit, rate, fee);
                }

                accounts.push_back(account);

                break;

            case 'd'://存入现金

                ifs >> index_ >> amount;
                getline(ifs,desc);
                accounts[index_]->deposit(date, amount, desc);

                break;

            case 'w'://取出现金

                ifs >> index_ >> amount ;
                getline(ifs,desc);
                accounts[index_]->withdraw(date, amount, desc);

                break;


            case 'c'://改变日期

                ifs >> day;
                date = Date(date.getYear(), date.getMonth(), day);
                    
                break;

            case 'n'://进入下个月

                if (date.getMonth() == 12)
                    date = Date(date.getYear() + 1, 1, 1);
                else
                    date = Date(date.getYear(), date.getMonth() + 1, 1);

                for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
                    (*iter)->settle(date);

                break;

        }
    }
    ifs.close();
}

int main() {

    read_cmd();

    cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit" << endl;
    ofstream ofs;
    ofs.open("commands.txt",ios::app);

    do{

        //显示日期和总金额

        date.show();
        cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";

        
        if(cin >> cmd && cmd != 'e') ofs<<cmd<<" ";
        else break;

        switch (cmd) {

        case 'a'://增加账户

            cin >> type >> id;
            ofs<<type<<" "<<id<<" ";
            if (type == 's') {
                cin >> rate;
                ofs<<rate;
                account = new SavingsAccount(date, id, rate);
            }
            else {
                cin >> credit >> rate >> fee;
                ofs<<credit<<" "<<rate<<" "<<fee;
                account = new CreditAccount(date, id, credit, rate, fee);
            }

            accounts.push_back(account);

            break;

        case 'd'://存入现金

            cin >> index_ >> amount;
            ofs<<index_<<" "<<amount<<" ";
            getline(cin, desc);
            ofs<<desc;
            accounts[index_]->deposit(date, amount, desc);

            break;

        case 'w'://取出现金

            cin >> index_ >> amount;
            ofs<<index_<<" "<<amount<<" ";
            getline(cin, desc);
            ofs<<desc;
            accounts[index_]->withdraw(date, amount, desc);

            break;

        case 's'://查询各账户信息

            for (size_t i = 0; i < accounts.size(); i++) {

                cout << "[" << i << "] ";

                accounts[i]->show();

                cout << endl;

            }

            break;

        case 'c'://改变日期

            cin >> day;
            ofs<<day;
            if (day < date.getDay())
                cout << "You cannot specify a previous day";
            else if (day > date.getMaxDay())
                cout << "Invalid day";
            else
                date = Date(date.getYear(), date.getMonth(), day);
                
            break;

        case 'n'://进入下个月

            if (date.getMonth() == 12)
                date = Date(date.getYear() + 1, 1, 1);
            else
                date = Date(date.getYear(), date.getMonth() + 1, 1);

            for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
                (*iter)->settle(date);

            break;

        case 'q'://查询一段时间内的账目

            date1 = Date::read();
            date2 = Date::read();
            Account::query(date1, date2);

            break;

        }
        ofs<<endl;
    } while (cmd != 'e');



    ofs.close();
    for_each(accounts.begin(), accounts.end(), deleter());

    return 0;

}