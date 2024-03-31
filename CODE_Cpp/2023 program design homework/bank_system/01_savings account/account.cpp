#include "account.h"
#include <bits/stdc++.h>
using namespace std;

SavingsAccount::SavingsAccount(int date,int id_,double rate_):date(date),id(id_),rate(rate_){
    cout<<'#'<<id<<"is created"<<endl;
};

double SavingsAccount::accumulate(int date){
    return accumulation + balance*(date-lastDate);
};

void SavingsAccount::record(int date,double amount){
    lastDate=date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance+=amount;
};

void SavingsAccount::show(){
    cout<<"#"<<id<<"\tBalance: "<<balance<<endl;
};

void SavingsAccount::deposit(int date,double amount){
    record(date,amount);
};

void SavingsAccount::withdraw(int date,double amount){
    if(amount>balance)
        cout<<"not enough money"<<endl;
    else    
        record(date,-amount);
};

void SavingsAccount::settle(int date){
    double interest=accumulate(date)*rate/365; //计算年息
    if(interest!=0)
        record(date,interest);
    accumulation=0;
};



int SavingsAccount::getId(){
    return id;
};
double SavingsAccount::getBalance(){
    return balance;
};
double SavingsAccount::getRate(){
    return rate;
};

