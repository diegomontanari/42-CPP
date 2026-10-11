#include "Zombie.hpp"

// new chiama il costruttore passandogli name, e il costruttore lo copia in _name con la lista di inizializzazione (: _name(name)) che abbiamo già scritto.
// Il _ davanti è solo una convenzione per riconoscere gli attributi della classe: non ha effetto sul compilatore. Ci serve a distinguere _name (l’attributo) da name (l’argomento).
Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}
