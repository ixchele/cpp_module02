#include <Fixed.hpp>
#include <iostream>

const int Fixed::_frac = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed &fixed) : _fixedValue(fixed._fixedValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
		_fixedValue = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member fucntion called" << std::endl;
	return _fixedValue;
}

void	Fixed::setRawBits(int const raw) {
	_fixedValue = raw;
}
