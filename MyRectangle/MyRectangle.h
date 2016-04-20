#pragma once

class MyRectangle
{
public:
	MyRectangle(double x, double y);
	~MyRectangle();

	double getArea(){ return area; }

	/* Define comparison operators*/
	friend inline bool operator== (const MyRectangle& lhs, const MyRectangle& rhs){ return lhs.area == rhs.area; }
	friend inline bool operator!= (const MyRectangle& lhs, const MyRectangle& rhs){ return !operator== (lhs, rhs); }
	friend inline bool operator<  (const MyRectangle &lhs, const MyRectangle &rhs){ return lhs.area < rhs.area; }
	friend inline bool operator>  (const MyRectangle& lhs, const MyRectangle& rhs){ return operator<  (rhs, lhs); }
	friend inline bool operator<= (const MyRectangle& lhs, const MyRectangle& rhs){ return !operator> (lhs, rhs); }
	friend inline bool operator>= (const MyRectangle& lhs, const MyRectangle& rhs){ return !operator< (lhs, rhs); }

private:
	double x = 0;
	double y = 0;
	double area = x * y;

};

MyRectangle::MyRectangle(double x, double y)
{
	this->area = x * y;
}

MyRectangle::~MyRectangle()
{
}