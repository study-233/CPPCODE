#include "date.h"
Date::Date(int year=0,int month=0,int day=0):year(year),month(month),day(day){
    if (day <= 0 || day > getMonthDay()){
		throw DateException();
    }
};
void Date::show() const{
    cout<<year<<'-'<<month<<'-'<<day;
};