#include "date.h"
#include <bits/stdc++.h>
using namespace std;

Date::Date():year(1),month(1),day(1){};

Date::Date(int year=0,int month=0,int day=0):year(year),month(month),day(day){
    if (day <= 0 || day > getMaxDay()){
        cout << "Invalid date:";
        show();
        cout << endl;
        exit(1);
    }
};

void Date::show(){
    cout<<year<<'-'<<month<<'-'<<day;
};

Date Date::read(){
	int year_,month_,day_;
	string datestr;
	cin>>datestr;
	istringstream iss(datestr);
	char separator;
	if (!(iss >> year_ >> separator >> month_ >> separator >> day_)) {
        cout<<"格式不对,请重新输入"<<endl;
    }
	return Date(year_,month_,day_);
};



bool Date::operator < (const Date& d) const
{
	if (year < d.year)
	{
		return true;
	}
	else if (year == d.year)
	{
		if (month < d.month)
			return true;
		else if ((month == d.month) && (day < d.day))
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Date::operator==(const Date& d)
{
	if ((year == d.year) && (month == d.month) && (day == d.day))
		return true;
	else
		return false;
}

bool Date::operator<=(const Date& d)
{
	return *this == d || *this < d;
}

bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d)
{
	return (*this > d || *this == d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	day += day;//先加
	//这里是while,因为如果是if的话，如果一次加了很大的数据减一次不一定能减得完!!!
	while(day > getMaxDay())
	{
		day -= getMaxDay();
		++month;
		if (month == 13)
		{
			++year;
			month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date tmp=*this;

   
	tmp += day;
	return tmp;
}


Date& Date::operator-=(int day)
{
	day -= day;
	while (day <= 0)
	{
		--month;
		if (month == 0)
		{
			--year;
			month = 12;
		}
		day += getMaxDay();
	}
	return *this;
}


Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	return *this += 1;
}

Date Date::operator++(int) 
{
	Date tmp = *this;
	
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this - 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
//日期-日期，计算两个日期之间相差多少天

int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;

	if (*this < d)
	{
		//赋值为-1的原因：因为这个函数是有顺序的d1-d2，如果遇到d1<d2，也就是小减大，最终返回的结果是个负数，所以说这里要变成-1。
		flag = -1;
		max = d;
		min = *this;
	}
	//定义一个变量
	int n = 0;
	// 用循环算两个日期中间的差值
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}
