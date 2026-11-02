#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		// Forma canonica (come in ex00)
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		// Novità di ex01: costruire un Fixed da un int o da un float
		Fixed(const int n);
		Fixed(const float f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Novità di ex01: riconvertire in float o in int
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

// Funzione libera (non membro): a sinistra di << c'è lo stream, non un Fixed
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
