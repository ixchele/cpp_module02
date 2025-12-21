#pragma once

#include <ostream>
class Fixed {
private:
	int					_fixedValue;
	static const int	_frac;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed &other);
	bool	operator<(const Fixed &other);
	bool	operator<=(const Fixed &other);
	bool	operator>=(const Fixed &other);
	bool	operator==(const Fixed &other);
	bool	operator!=(const Fixed &other);
	Fixed	operator+(const Fixed &other);
	Fixed	operator-(const Fixed &other);
	Fixed	operator*(const Fixed &other);
	Fixed	operator/(const Fixed &other);
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
};

std::ostream &operator<<(std::ostream &ostr, const Fixed &fixed);
