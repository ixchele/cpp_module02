#pragma once

class Fixed {
private:
	int					_fixedValue;
	static const int	_frac;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
