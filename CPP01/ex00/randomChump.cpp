
#include "Zombie.cpp"

void randomChump(std::string name)
{
	Zombie randomChump = Zombie(name);
	randomChump.announce();
}