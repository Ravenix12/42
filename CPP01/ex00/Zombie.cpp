

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string zName): name(zName)
{ 
	std::cout << "Zombie " << name << " created\n";
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed\n";
}

void Zombie::announce( void )
{
	std::cout << name << "BraiiiiiiinnnzzzZ...\n";
}
