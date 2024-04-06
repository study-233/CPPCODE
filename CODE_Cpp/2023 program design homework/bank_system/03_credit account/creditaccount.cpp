#include "creditaccount.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

CreditAccount::CreditAccount(Date date, string id, double credite, double rate, double fee)
:Account(date,id),acc(date,0), credit(credite),rate(rate),fee(fee)//对父类，以及类对象初始化
{}
//完成对类的，展示内容

// 信用账户存钱操作
void CreditAccount::deposit(Date date, double amount, string use_score)
{
    amount = floor(amount * 100 + 0.5 ) / 100;//amount是变动金额，一直为正数
    //cout<<getBalance()<<endl;
    acc.change(date,change_balance(amount));
    date.show();
    cout << "\t#" << getId() << " \t"<<amount<<"\t"<<getBalance() <<"\t"<<use_score<< endl;

}

//信用账户取钱操作
//取钱操作需要和信用对比一下
void CreditAccount::withdraw(Date date, double amount, string use_score)
{
    if(credit+getBalance()-amount>=0){
    amount = floor(amount * 100 + 0.5 ) / 100;
    acc.change(date,change_balance(-amount));
    date.show();
    cout << "\t#" << getId() << " \t"<<-amount<<"\t"<<getBalance() <<"\t"<<use_score<< endl;} else{
        cout<<"信用额度不足！！"<<endl;
    }
}

//结算利息
void CreditAccount::settle(Date date) {
    acc.change(date,0);
    interest=acc.getSum(date)*rate; //计算利息
    //那个rate指的是日利率，按日欠款计息，将日累积直接乘以日利率就是利息
    //cout<<"利息： "<<interest<<endl;
    if(date.getMonth()==1&&date.getDay()==1){
        interest-=fee;//处理年费
        change_balance(interest);//在余额中加上利息
        date.show();
        //cout<<endl;
        cout << "\t#" << getId() << " \t"<<interest<<"\t"<<getBalance() <<"\t"<<"annual fee"<< endl;

    }else{
    change_balance(interest);//在余额中加上利息
    date.show();
    //cout<<endl;
    cout << "\t#" << getId() << " \t"<<interest<<"\t"<<getBalance() <<"\t"<<"interest"<< endl;
    }
    interest=0;
    acc.reset(date,0);


}
void CreditAccount::show() {//子类需要重写
    cout << getId() << "\tBalance: " << getBalance()<<"\t"<<"Available credit:"<<credit+getBalance();

}
