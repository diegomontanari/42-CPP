#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

// La rubrica: un array statico di 8 contatti (niente new, come chiede il subject).
class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search() const;

	private:
		static const int	MAX_CONTACTS = 8;

		Contact	_contacts[MAX_CONTACTS];
		int		_count;	// quanti contatti sono salvati (al massimo 8)
		int		_next;	// posizione in cui scrivere il prossimo (il più vecchio quando è piena)

		// Funzioni di aiuto usate solo dentro la classe: quindi private
		static bool			_readField(const std::string &prompt, std::string &out);
		static std::string	_formatColumn(const std::string &text);
		void				_printTable() const;
		void				_printContact(int index) const;
};

#endif
