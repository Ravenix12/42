

#include "Zombie.cpp"

Zombie* Zombie::newZombie(std::string name)
{
	Zombie* zombie = new Zombie(name);

	return zombie;
}
