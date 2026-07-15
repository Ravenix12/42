/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:48:43 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/15 12:19:57 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "Default constructor called\n";
}
ClapTrap::ClapTrap(std::string Name) : name(Name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap " << name << " constructor called\n";
}
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << " destructor called\n";
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
    {
        this->name = other.getName();
        this->hitPoints = other.getHitPoints();
        this->energyPoints = other.getEnergyPoints();
        this->attackDamage = other.getAttackPoints();
    }
    return *this;
}
ClapTrap::ClapTrap(const ClapTrap &dup) : name(dup.getName()), hitPoints(dup.getHitPoints()), energyPoints(dup.getEnergyPoints()), attackDamage(dup.getAttackPoints()) {
		std::cout << "Copy constructor called\n";
}
void ClapTrap::attack(const std::string &target){
	if (energyPoints <= 0 || hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have enough energy/hit points to attack\n";
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount){
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead. Let them rest in peace\n";
		return;		
	}
	hitPoints -= (amount > hitPoints) ? hitPoints : amount;
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead\n";
		return;		
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
}
void ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints <= 0 || hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have enough energy/hit points to repair\n";
		return;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs " << amount << " points of damage!\n";
}

std::string ClapTrap::getName() const{
	return name;
}
int ClapTrap::getHitPoints() const{
	return hitPoints;
}
int ClapTrap::getEnergyPoints() const{
	return energyPoints;
}
int ClapTrap::getAttackPoints() const{
	return attackDamage;
}
