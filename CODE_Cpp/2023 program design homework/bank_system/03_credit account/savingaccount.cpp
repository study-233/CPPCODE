#include "savingaccount.h"
#include "date.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;


SavingsAccount::SavingsAccount(Date date, string id, double rate)
: Account(date,id),acc(date,0) //对父类，以及类对象初始化
{
    this->rate=rate;
}

// 储蓄账户存钱操作
void SavingsAccount::deposit(Date date, double amount, string use_score)
{
    amount = floor(amount * 100 + 0.5) / 100;
    acc.change(date,change_balance(amount));
    date.show();
    cout << "\t#" << getId() << " \t"<<amount<<"\t"<<getBalance() <<"\t"<<use_score<< endl;

}

//储蓄账户取钱操作
void SavingsAccount::withdraw(Date date, double amount, string use_score)
{
    amount = floor(amount * 100 + 0.5) / 100;
    acc.change(date,change_balance(-amount));
    date.show();
    cout << "\t#" << getId() << " \t"<<-amount<<"\t"<<getBalance() <<"\t"<<use_score<< endl;
}

//结算利息
void SavingsAccount::settle(Date date) {
    acc.change(date,0);
    interest=acc.getSum(date)*rate/date.distance(Date(date.getYear() - 1, 1, 1)); //计算年息

    change_balance(interest);//在余额中加上利息

    date.show();
    cout << "\t#" << getId() << " \t"<<floor(interest*100)/100<<"\t"<<getBalance() <<"\t"<<"interest"<< endl;
    //这里对年息进行保留两位小数


}

