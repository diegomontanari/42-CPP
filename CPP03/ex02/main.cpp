#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

static void	title(const std::string &text)
{
	std::cout << std::endl << "=============== " << text << " ===============" << std::endl;
}

static void	say(const std::string &text)
{
	std::cout << "   >> " << text << std::endl;
}

int	main(void)
{
	title("TEST 1: CONSTRUCTION CHAIN");
	say("We create a FragTrap named Baymax: FIRST ClapTrap constructor, THEN FragTrap constructor.");
	FragTrap	hero("Baymax");

	title("TEST 2: DEFAULT CONSTRUCTOR");
	FragTrap	nobody;

	title("TEST 3: ATTACK (inherited from ClapTrap, FragTrap does NOT rewrite it)");
	say("The message says 'ClapTrap' (parent's attack) but the damage is 30 (FragTrap value).");
	hero.attack("Skynet");

	title("TEST 4: INHERITED takeDamage AND beRepaired");
	say("Baymax takes 40 damage: hit points 100 -> 60.");
	hero.takeDamage(40);
	say("Baymax repairs 15: hit points 60 -> 75.");
	hero.beRepaired(15);

	title("TEST 5: HIGH FIVES (new function, only FragTrap has it)");
	hero.highFivesGuys();

	title("TEST 6: COPY CONSTRUCTOR AND ASSIGNMENT");
	say("Copy: ClapTrap copy constructor, then FragTrap copy constructor.");
	FragTrap	copy(hero);
	FragTrap	target("C-3PO");
	say("Assignment target = hero: BOTH assignment messages appear (FragTrap calls ClapTrap).");
	target = hero;
	target.highFivesGuys();

	title("TEST 7: SCAVTRAP AND FRAGTRAP TOGETHER (two separate chains)");
	say("Different energy: ScavTrap 50, FragTrap 100. Different constructor messages.");
	ScavTrap	scav("R2-D2");
	scav.attack("Skynet");

	title("END: DESTRUCTION CHAIN (reverse order, child first, then parent)");
	return (0);
}
