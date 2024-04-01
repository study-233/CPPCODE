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

    double accumulate(const Date &date);
    void record(const Date &date,double amount,const string & desc);

public:

    SavingsAccount(const Date &date,const string & id,double rate);
    string getId(){return id;};
    double getBalance(){return balance;};
    double getRate(){return rate;};
    static double getTotal(){return total;};
    
    void show();
    void deposit(const Date &date,double amount,const string & desc);
    void withdraw(const Date &date,double amount,const string & desc);
    void settle(const Date &date);


};


#endif