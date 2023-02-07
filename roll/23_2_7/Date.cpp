#include "Date.h"
void Date::print() const
{
	//_year = 1900; 加上const会让this从Date* this变为 const Date * this
	//* this 不能被修改
	cout << _year << "年"  << _month << "月" << _day << "日" << endl;
}

int Date::GetMonthDay(int year, int month) const
{
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return monthArray[month];
	}
}

// <
bool Date::operator<(const Date& d) const
{
	//this<d
	if (_year > d._year)
	{
		return false;
	}
	else if (_year == d._year && _month > d._month)
	{
		return false;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return false;
	}
	return true;
}
// ==
bool Date::operator==(const Date& d) const
{
	return _year == d._year && _month == d._month && _day == d._day;
}
// !=
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}
// <=
bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}
// >
bool Date::operator>(const Date & d) const
{
	return !(*this <= d);
}
// >=
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

// +=
Date& Date::operator+=(int day) 
{
	if (day < 0)
	{
		*this -= -day;
		return *this;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}	
	}
	return *this;
}
// +
Date Date::operator+(int day)
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

// -=
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
// -
Date  Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

//++d1
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//d1++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

//--d1
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//d1--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//d1-d2
int Date::operator-(const Date& d)
{
	Date Max = *this;
	Date Min = d;
	int flag = 1;
	int n = 0;
	if (Max < Min)
	{
		Max = d;
		Min = *this;
		flag = -1;
	}

	while (Min != Max)
	{
		Min++;
		n++;
	}
	return flag * n;
}


//让cout能到第一个参数，Date类到第二个参数
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "" << d._month << "" << d._day << "" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}