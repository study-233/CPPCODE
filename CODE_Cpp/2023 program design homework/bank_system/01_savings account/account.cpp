#include "account.h"
#include <bits/stdc++.h>
using namespace std;

SavingsAccount::SavingsAccount(int date,int id_,double rate_){
    id=id_;
    lastDate=date;
    rate=rate_;
};

double SavingsAccount::accumulate(int date){

};

void SavingsAccount::record(int date,double amount){

};

void SavingsAccount::show(){
    cout<<"#"<<getId();
    cout<<"         Balance: "<<getBalance()<<endl;
};

void SavingsAccount::deposit(int date,double amount){

};

void SavingsAccount::withdraw(int date,double amount){

};

void SavingsAccount::settle(int date){

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