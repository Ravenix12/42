/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:20:57 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/15 13:05:23 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "Default constructor called\n";
}
ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) {
	std::cout << "ScavTrap " << name << " constructor called\n";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}
ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << name << " destructor called\n";}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	std::cout << "ScavTrap Copy assignment operator called\n";
	if (this != &other)
    {
        this->name = other.getName();
        this->hitPoints = other.getHitPoints();
        this->energyPoints = other.getEnergyPoints();
        this->attackDamage = other.getAttackPoints();
    }
    return *this;
}
ScavTrap::ScavTrap(const ScavTrap &dup): ClapTrap(dup) {
	std::cout << "ScavTrap Copy constructor called\n";
}
void ScavTrap::attack(const std::string &target){
	if (energyPoints <= 0 || hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " doesn't have enough energy/hit points to attack\n";
		return;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}
void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode.\n";
}