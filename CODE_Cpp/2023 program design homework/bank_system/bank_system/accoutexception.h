#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include <stdexcept>
#include "account.h"
class AccoutException:public runtime_error{
    private:
        const Account* account;
    public:
        AccoutException(Account * _account):account(_account){};
        const char* what() const noexcept override {
            string s1 = "Not enough money in this account:";
            string s2 = account->getId();
            string s3 = to_string(account->getBalance());
            static string s4 = s1+s2+"\tbalance:"+s3;
            return s4.c_str();
        };
}


#endif