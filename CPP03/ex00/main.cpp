#include "ClapTrap.hpp"
#include <iostream>

// Prints a big title before each test group.
static void	title(const std::string &text)
{
	std::cout << std::endl << "=============== " << text << " ===============" << std::endl;
}

// Prints a line that explains what the NEXT line(s) of output are testing.
static void	say(const std::string &text)
{
	std::cout << "   >> " << text << std::endl;
}

int	main(void)
{
	title("TEST 1: CONSTRUCTORS (default and with a name)");
	say("Now we create a ClapTrap WITHOUT a name: the DEFAULT constructor must be called.");
	ClapTrap	nobody;
	say("Now we create a ClapTrap named R2-D2: the NAME constructor must be called.");
	ClapTrap	bolt("R2-D2");

	title("TEST 2: ATTACK (costs 1 energy point)");
	say("R2-D2 attacks Skynet. Attack damage is 0 in ex00, so 'causing 0 points of damage' is correct.");
	bolt.attack("Skynet");

	title("TEST 3: TAKE DAMAGE (partial damage, then damage bigger than the hit points)");
	say("R2-D2 takes 4 damage: hit points must go from 10 to 6.");
	bolt.takeDamage(4);
	say("R2-D2 takes 1000 damage: hit points must stop at 0 (NOT a huge number: unsigned int trap).");
	bolt.takeDamage(1000);

	title("TEST 4: REPAIR (gives hit points back, costs 1 energy point)");
	ClapTrap	nova("WALL-E");
	say("WALL-E takes 3 damage: hit points 10 -> 7.");
	nova.takeDamage(3);
	say("WALL-E repairs 2: hit points 7 -> 9.");
	nova.beRepaired(2);

	title("TEST 5: A ROBOT WITH 0 HIT POINTS CANNOT DO ANYTHING");
	say("R2-D2 has 0 hit points (see test 3). Attack must be refused.");
	bolt.attack("Skynet");
	say("Repair must be refused too.");
	bolt.beRepaired(5);
	say("Taking damage again says it is already out of hit points.");
	bolt.takeDamage(1);

	title("TEST 6: NO ENERGY LEFT (10 energy points = 10 actions)");
	ClapTrap	tired("Marvin");
	say("Marvin attacks 10 times: every attack costs 1 energy point, so energy goes 10 -> 0.");
	for (int i = 0; i < 10; i++)
		tired.attack("Skynet");
	say("11th action: attack must be refused, no energy left.");
	tired.attack("Skynet");
	say("Repair must be refused too, no energy left.");
	tired.beRepaired(1);

	title("TEST 7: COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR");
	say("Baymax is our MODEL: it attacks (energy 10 -> 9) and takes 3 damage (hit points 10 -> 7).");
	ClapTrap	source("Baymax");
	source.attack("R2-D2");
	source.takeDamage(3);

	say("COPY CONSTRUCTOR: 'copy' is born from Baymax. It must start with 7 hit points and 9 energy, not 10 and 10.");
	ClapTrap	copy(source);

	say("C-3PO is born on its own (a normal ClapTrap with 10 hit points and 10 energy).");
	ClapTrap	target("C-3PO");

	say("ASSIGNMENT OPERATOR: 'target = source'. C-3PO already exists and gets OVERWRITTEN with Baymax's values.");
	say("From now on it is called 'Baymax' too, and has 7 hit points and 9 energy.");
	target = source;

	say("Now Baymax takes 2 damage (7 -> 5). 'copy' and 'target' are INDEPENDENT objects: they must stay at 7.");
	source.takeDamage(2);

	say("'copy' repairs 1 (7 -> 8, energy 9 -> 8). Messages say 'Baymax' because the copy has the same name.");
	copy.beRepaired(1);

	say("SELF-ASSIGNMENT: 'target = same' where 'same' is a reference to target itself. The 'if (this != &other)' must protect us.");
	ClapTrap	&same = target;
	target = same;

	title("END: DESTRUCTORS (reverse order of creation)");
	say("Last created is destroyed first: target (shows 'Baymax'), copy (shows 'Baymax'), source, Marvin, WALL-E, R2-D2, nobody (Default).");
	return (0);
}
