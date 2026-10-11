#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string &name) : _name(name)
{
}

Zombie::~Zombie()
{
    std::cout << _name << " Is destroyed" << std::endl;
}

// announce è una funzione membro (method python, ovvero che agisce su qualcosa)
// va chiamata con il punto e non riceve argomenti perché l'argomento sta già dentro
// da dove lo riconosci che è una funzione membro? Da due indizi, sia in come la scrivi che in come la dichiari:
// 1) Nel .cpp, il Classe:: davanti al nome: void Zombie::announce(void) è un membro (appartiene a Zombie). void randomChump(std::string name) non ha nessun Zombie::, quindi è libera
// 2) Nell’header, dove sta: announce è dichiarata dentro class Zombie { ... };, randomChump fuori dalla classe
// Conseguenza: una funzione membro ha dentro di sé uno zombie nascosto (this), e per questo può usare _name senza dover ricevere niente. Una funzione libera non ha nessun oggetto nascosto, quindi lo zombie devi crearlo o riceverlo tu
void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
