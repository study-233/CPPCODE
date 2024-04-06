#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H
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
        double getSum(Date date) const {return sum;};
        void change(Date date,double value);
        void reset(Date date,double value);
};

#endif