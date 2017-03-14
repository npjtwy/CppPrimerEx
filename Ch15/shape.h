#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
class Shape
{
public:
	typedef std::pair<double, double>    Coordinate;

	Shape() = default;
	Shape(std::string n): name(n) {}

	virtual double area() const = 0;
	virtual double perimeter() const = 0;		//求周长
protected:
private:
	std::string name;
};

class Rectangle : public Shape		//矩形
{
public:
	Rectangle() = default;
	Rectangle(const std::string n,
		const Coordinate a,
		const Coordinate b,
		const Coordinate c,
		const Coordinate d) :
		Shape(n), a(a), b(b), c(c), d(d) {}
protected:
	//std::string name;
	Coordinate a;
	Coordinate b;
	Coordinate c;
	Coordinate d;
};