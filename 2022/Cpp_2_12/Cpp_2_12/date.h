#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);
	void print();
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	Date operator+(int day);
	Date& operator++();
	Date operator++(int);
private:
	int _year;
	int _month;
	int _day;
};