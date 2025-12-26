#include <Point.hpp>
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	// Triangle ABC
	Point A(0, 0);
	Point B(5, 0);
	Point C(0, 5);

	// Points
	Point P1(1, 1);
	Point P2(5, 5);
	Point P3(0, 2);
	Point P4(2, 1);

	std::cout << std::boolalpha;
	std::cout << "P1 inside: " << bsp(A, B, C, P1) << std::endl;
	std::cout << "P2 inside: " << bsp(A, B, C, P2) << std::endl;
	std::cout << "P3 inside: " << bsp(A, B, C, P3) << std::endl;
	std::cout << "P4 inside: " << bsp(A, B, C, P4) << std::endl;

	return 0;
}
