#pragma once

using namespace std;

class Rectangle
{
public:
	Rectangle(double &x, double &y);
	~Rectangle();

	double getArea(){ return area; }

	/* Define comparison operators*/
	friend inline bool operator==(const Rectangle& lhs, const Rectangle& rhs){ return lhs.area == rhs.area; }
	friend inline bool operator!=(const Rectangle& lhs, const Rectangle& rhs){ return !operator==(lhs, rhs); }

	friend inline bool operator<(const Rectangle &lhs, const Rectangle &rhs){ return lhs.area < rhs.area; }
	friend inline bool operator>(const Rectangle& lhs, const Rectangle& rhs){ return  operator< (rhs, lhs); }
	friend inline bool operator<=(const Rectangle& lhs, const Rectangle& rhs){ return !operator> (lhs, rhs); }
	friend inline bool operator>=(const Rectangle& lhs, const Rectangle& rhs){ return !operator< (lhs, rhs); }

private:
	double x = 0;
	double y = 0;
	double area = x * y;

};

Rectangle::Rectangle(double &x, double &y)
{
	this->area = x * y;
}

Rectangle::~Rectangle()
{
}