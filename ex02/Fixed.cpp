#include <Fixed.hpp>
#include <iostream>
#include <cmath>
#include <ostream>

const int Fixed::_frac = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed &fixed) : _fixedValue(fixed._fixedValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << _frac);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits((int)roundf(value * (1 << _frac)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
		_fixedValue = fixed.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &ostr, const Fixed &fixed) {
	ostr << fixed.toFloat();
	return ostr;
}

int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member fucntion called" << std::endl;
	return _fixedValue;
}

void	Fixed::setRawBits(int const raw) {
	_fixedValue = raw;
}

float	Fixed::toFloat(void) const {
	return (float)getRawBits() / (1 << _frac);
}

int	Fixed::toInt(void) const {
	return getRawBits() >> _frac;
}

bool	Fixed::operator>(const Fixed &other) {
	return toInt() > other.toInt();
}

bool	Fixed::operator<(const Fixed &other) {
	return toInt() < other.toInt();
}

bool	Fixed::operator>=(const Fixed &other) {
	return toInt() >= other.toInt();
}

bool	Fixed::operator<=(const Fixed &other) {
	return toInt() <= other.toInt();
}

bool	Fixed::operator==(const Fixed &other) {
	return toInt() == other.toInt();
}

bool	Fixed::operator!=(const Fixed &other) {
	return toInt() != other.toInt();
}
