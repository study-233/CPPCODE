#include "account.h"
#include "Date.h"
#include <bits/stdc++.h>
using namespace std;

double SavingsAccount::total=0;

SavingsAccount::SavingsAccount(Date date,string id_,double rate_):lastDate(date),id(id_),rate(rate_),balance(0),accumulation(0){
    cout<<lastDate<<"\t#"<<id<<" is created"<<endl;
};

double SavingsAccount::accumulate(Date date){
    return accumulation + balance*(date-lastDate);
};

void SavingsAccount::record(Date date,double amount){
    accumulation=accumulate(date);
    lastDate=date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance+=amount;
    total+=amount;
    cout<<lastDate<<"\t#"<<id<<"\t";
    cout.setf(ios::left);
    cout.width(5);
    cout<<amount<<"   "<<balance<<endl;
};

void SavingsAccount::show(){
    cout<<"#"<<id<<"\tBalance: "<<balance;
};

void SavingsAccount::deposit(Date date,double amount){
    record(date,amount);
};

void SavingsAccount::withdraw(Date date,double amount){
    if(amount>balance)
        cout<<"not enough money"<<endl;
    else    
        record(date,-amount);
};

void SavingsAccount::settle(Date date){
    double interest=accumulate(date)*rate/365; //计算年息
    if(interest!=0)
        record(date,interest);
    accumulation=0;
};



string SavingsAccount::getId(){
    return id;
};
double SavingsAccount::getBalance(){
    return balance;
};
double SavingsAccount::getRate(){
    return rate;
};
double SavingsAccount::getTotal(){
    return total;
};

