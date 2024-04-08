#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include <stdexcept>

class AccoutException:public runtime_error{
    const Account* account;
}


#endif