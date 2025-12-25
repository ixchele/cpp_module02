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

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;
	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
	static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed	&min(Fixed &fixed1, Fixed &fixed2);
	static Fixed	&max(Fixed &fixed1, Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &ostr, const Fixed &fixed);
