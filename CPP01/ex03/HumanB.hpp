#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <cstddef>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon;  // PUNTATORE: HumanB PUÒ non avere arma

public:
	HumanB(const std::string &name);
	~HumanB();

	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif