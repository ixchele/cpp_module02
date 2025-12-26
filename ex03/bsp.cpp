#include <Fixed.hpp>
#include <Point.hpp>

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	c1 = Point::cross(a, b, point);
	Fixed	c2 = Point::cross(b, c, point);
	Fixed	c3 = Point::cross(c, a, point);

	bool has_neg = (c1 < Fixed(0)) || (c2 < Fixed(0)) || (c3 < Fixed(0));
	bool has_pos = (c1 > Fixed(0)) || (c2 > Fixed(0)) || (c3 > Fixed(0));

	return !(has_neg && has_pos);
}
