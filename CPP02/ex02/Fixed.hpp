#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		// Forma canonica
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		// Costruttori di conversione (ex01)
		Fixed(const int n);
		Fixed(const float f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Novità di ex02: i 6 operatori di confronto
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// I 4 operatori aritmetici: restituiscono un Fixed NUOVO (per copia)
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		// Incremento e decremento: pre (++a) e post (a++)
		Fixed	&operator++(void);		// ++a
		Fixed	operator++(int);		// a++  (l'int finto serve solo a distinguerlo)
		Fixed	&operator--(void);		// --a
		Fixed	operator--(int);		// a--

		// min e max: static, perché non lavorano su un oggetto ma su due argomenti
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif
