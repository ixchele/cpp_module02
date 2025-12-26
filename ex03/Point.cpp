#include <Point.hpp>

Point::Point() {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY()) {}

Point::~Point() {}

Point	&Point::operator=(const Point &other) {
	(void)other;
	return *this;
}

const Fixed	Point::getX(void) const {
	return _x;
}

const Fixed	Point::getY(void) const {
	return _y;
}

Fixed Point::cross(Point a, Point b, Point c)
{
	return (b.getX() - a.getX()) * (c.getY() - a.getY())
	     - (b.getY() - a.getY()) * (c.getX() - a.getX());
}
