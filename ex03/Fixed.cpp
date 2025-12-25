#include <Fixed.hpp>
#include <iostream>
#include <cmath>
#include <ostream>

const int Fixed::_frac = 8;

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed &fixed) : _fixedValue(fixed._fixedValue) {
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(value << _frac);
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;
	setRawBits((int)roundf(value * (1 << _frac)));
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &fixed) {
	// std::cout << "Copy assignement operator called" << std::endl;
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

bool	Fixed::operator>(const Fixed &other) const {
	return getRawBits() > other.getRawBits();
}

bool	Fixed::operator<(const Fixed &other) const {
	return getRawBits() < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed &other) const {
	return getRawBits() >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed &other) const {
	return getRawBits() <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed &other) const {
	return getRawBits() == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed &other) const {
	return getRawBits() != other.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &other) const {
	Fixed	result;
	result.setRawBits(getRawBits() + other.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed	result;
	result.setRawBits(getRawBits() - other.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed result;
	long tmp = (long)getRawBits() * other.getRawBits();
	result.setRawBits(tmp >> _frac);
	return result;
}

Fixed	Fixed::operator/(const Fixed &other) const {
	Fixed result;
	long tmp = ((long)getRawBits() << _frac) / other.getRawBits();
	result.setRawBits(tmp);
	return result;
}

Fixed	&Fixed::operator++(void) {
	return _fixedValue++, *this; 
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	return _fixedValue++, tmp; 
}

Fixed	&Fixed::operator--(void) {
	return _fixedValue--, *this; 
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	return _fixedValue--, tmp; 
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 > fixed2 ? fixed2 : fixed1);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 < fixed2 ? fixed2 : fixed1);
}

Fixed	&Fixed::min(Fixed &fixed1,Fixed &fixed2) {
	return (fixed1 > fixed2 ? fixed2 : fixed1);
}

Fixed	&Fixed::max(Fixed &fixed1,Fixed &fixed2) {
	return (fixed1 < fixed2 ? fixed2 : fixed1);
}
