#ifndef ACCOUNT_H
#define  ACCOUNT_H
#include <bits/stdc++.h>
#include "Date.h"
using namespace std;

class SavingsAccount{
private:
    string id;
    double balance;
    double rate;
    Date lastDate;
    double accumulation;
    static double total;
    double accumulate(Date date);
    void record(Date date,double amount);
    int getId();
    double getBalance();
    double getRate();
    double getTotal();
public:
    SavingsAccount(Date date,string id,double rate);
    void show();
    void deposit(Date date,double amount);
    void withdraw(Date date,double amount);
    void settle(Date date);


};


#endif