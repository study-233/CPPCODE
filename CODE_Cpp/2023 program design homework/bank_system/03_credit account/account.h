#ifndef ACCOUNT_H
#define  ACCOUNT_H
#include <bits/stdc++.h>
#include "Date.h"
using namespace std;


class Accumulator{
    private:
        Date lastDate;
        double value;
        double sum;
    public:
        Accumulator(Date date,double value);
        double getdSum(Date date) const;
        void change(Date date,double value);
        void reset(Date date,double value);
};



class account{
    private:
        string id;
        double balance;
        double total;
    public:
        account(Date date,string id);
        void record(Date date,double amount,const string desc);

        void error(string msg) const;
        int getId() const {return id;};
        double getBalance() const {return balance;};
        void show() const;    
        static double getTotal(){return total;};
};


class SavingsAccount: public account{
    private:
        Accumulator acc;
        double rate;

    public:

        SavingsAccount(Date date,string id,double rate);
        double getRate() const {return rate;};
        static double getTotal(){return total;};
        
        void deposit(const Date &date,double amount,const string desc);
        void withdraw(const Date &date,double amount,const string desc);
        void settle(Date date);


};

class CreditAccount: public account{
    private:
        Accumulator acc;
        double rate;
        double credit;
        double fee;

    public:
        double getDebt() const;
        CreditAccount(Date date,string id,double credit,double rate,double fee);
        double getCredit() const {return credit;};
        double getRate() const {return rate;};
        double getFee() const {return fee;};
        double getAvailableCredit() const ;

        void deposit(const Date &date,double amount,string desc);
        void withdraw(const Date &date,double amount,string desc);
        void settle(Date date);
        void show() const;

};
#endif