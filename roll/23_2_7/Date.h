#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Date
{
	// 友元
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int year = 0,int month = 0,int day = 0) : _year(10), _month(10), _day(10)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//Date(const Date&) {} 会浅拷贝的可以不写

	void print() const;
	int GetMonthDay(int year,int month) const;

	bool operator<(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;

	Date& operator+=(int day);
	Date  operator+(int day);

	Date& operator-=(int day);
	Date  operator-(int day);

	//++d1
	Date& operator++();
	//d1++
	Date operator++(int);

	//--d1
	Date& operator--();
	//d1--
	Date operator--(int);


	//d1-d2
	int operator-(const Date& d);
		
private:
	int _year;
	int _month;
	int _day;
};