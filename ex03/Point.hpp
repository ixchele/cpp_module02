#pragma once
#include <Fixed.hpp>

class Point {
	private:
	const Fixed _x;
	const Fixed	_y;

	public:
	Point();
	Point(const float x, const float y);
	Point(const Point &copy);
	~Point();

	Point	&operator=(const Point &other);

	const Fixed	getX(void) const;
	const Fixed	getY(void) const;


	static Fixed	cross(Point a, Point b, Point c);
};
