#ifndef ACCOUNT_H
#define  ACCOUNT_H

class SavingsAccount{
private:
    int id;
    double balance;
    double rate;
    int lastDate;
    double accumulation;
    double accumulate(int date);
    void record(int date,double amount);
    int getId();
    double getBalance();
    double getRate();

public:
    SavingsAccount(int date,int id,double rate);
    void show();
    void deposit(int date,double amount);
    void withdraw(int date,double amount);
    void settle(int date);


};


#endif