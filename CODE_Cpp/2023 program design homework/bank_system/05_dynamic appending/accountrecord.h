#ifndef __ACCOUNT_RECORD__
#define __ACCOUNT_RECORD__

#include <string>
using namespace std;

class AccountRecord{        //账目记录
    private:
        Date date;
        const Account *account;
        double amount;
        double balance;
        string desc;
    public:
        AccountRecord(Date date,const Account *account,double amount,double balance,string desc)
        :data(data),account(account),amount(amount),balance(balance),desc(desc);
};



#endif