#include "ScavTrap.hpp"
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
	title("TEST 1: CONSTRUCTION CHAIN (parent first, then child)");
	say("We create a ScavTrap named R2-D2.");
	say("Expected order: FIRST the ClapTrap constructor, THEN the ScavTrap constructor.");
	ScavTrap	guard("R2-D2");

	title("TEST 2: DEFAULT CONSTRUCTOR");
	say("A ScavTrap without a name: ClapTrap default constructor, then ScavTrap default constructor.");
	ScavTrap	nobody;

	title("TEST 3: ATTACK IS OVERRIDDEN (ScavTrap message, 20 damage)");
	say("R2-D2 attacks Skynet: the message must start with 'ScavTrap', NOT 'ClapTrap',");
	say("and the damage must be 20 (ScavTrap value), not 0 (ClapTrap value).");
	guard.attack("Skynet");

	title("TEST 4: INHERITED FUNCTIONS (takeDamage and beRepaired come from ClapTrap)");
	say("R2-D2 takes 30 damage: hit points 100 -> 70. The message says 'ClapTrap' because");
	say("ScavTrap does NOT rewrite takeDamage: it uses the parent's one. This is correct.");
	guard.takeDamage(30);
	say("R2-D2 repairs 10: hit points 70 -> 80 (again the parent's function).");
	guard.beRepaired(10);

	title("TEST 5: GUARD GATE (new function, only ScavTrap has it)");
	guard.guardGate();

	title("TEST 6: ENERGY RUNS OUT (ScavTrap has 50 energy points)");
	ScavTrap	tired("Marvin");
	say("Marvin attacks 50 times: every attack costs 1 energy point (output hidden, too long).");
	std::cout.setstate(std::ios_base::failbit);
	for (int i = 0; i < 50; i++)
		tired.attack("Skynet");
	std::cout.clear();
	say("Energy is now 0: the next attack must be REFUSED.");
	tired.attack("Skynet");

	title("TEST 7: NO HIT POINTS LEFT");
	ScavTrap	broken("WALL-E");
	say("WALL-E takes 1000 damage: hit points must stop at 0.");
	broken.takeDamage(1000);
	say("Now WALL-E tries to attack: it must be REFUSED.");
	broken.attack("Skynet");

	title("TEST 8: COPY CONSTRUCTOR (a NEW ScavTrap is born from R2-D2)");
	say("Expected: ClapTrap copy constructor, then ScavTrap copy constructor.");
	say("The copy has R2-D2's current values (80 hit points, 49 energy).");
	ScavTrap	copy(guard);
	say("The copy attacks: name R2-D2, 20 damage.");
	copy.attack("Skynet");

	title("TEST 9: ASSIGNMENT OPERATOR (both objects already exist)");
	ScavTrap	target("C-3PO");
	say("target = guard: ScavTrap operator= calls ClapTrap operator=, so BOTH messages appear.");
	target = guard;
	say("target now has R2-D2's name and values: its attack must say R2-D2.");
	target.attack("Skynet");
	say("Self-assignment: the check this != &other skips the copy (only the message).");
	ScavTrap	&same = target;
	target = same;

	title("END: DESTRUCTION CHAIN (child first, then parent, reverse creation order)");
	say("For each object: FIRST the ScavTrap destructor, THEN the ClapTrap destructor.");
	say("Reverse order: target (now called R2-D2, after the assignment), copy (R2-D2), WALL-E, Marvin, nobody (Default), R2-D2.");
	return (0);
}
