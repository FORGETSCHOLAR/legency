#include "Date.h"


void TestDemo1()
{
	Date d1;
	d1.print();

	Date d2(2023, 2, 7);
	d2.print();
	cout << d2.GetMonthDay(2000, 1) << endl;
}

void TestDemo2()
{
	Date d1(2022, 2, 9);
	Date d2(2023, 2, 10);
	d1.print();
	d2.print();
	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;

}

void TestDemo3()
{
	Date d1(2022, 1, 20);
	Date d2(2023, 2, 8);
	cout << (d2 - d1) << endl;

	d1.print();
	d1.operator+=(1);
	d1.print();

	cout << d1 << endl;
}
int main()
{
	TestDemo3();
}