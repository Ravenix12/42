/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:50:13 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:37:47 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():Animal("Dog"){
	std::cout << "Dog constructor called\n";
	brain = new Brain();
}
Dog::~Dog(){
	delete brain;
	std::cout << "Dog destructor called\n";
}
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
        this->type = other.type;
    return *this;
}
Dog::Dog(const Dog &dup) : Animal(dup){
	std::cout << "Dog Copy constructor called\n";
	this->brain = new Brain(*dup.brain);
}

void Dog::makeSound() const{
	std::cout << "woof woof\n";
}

void Dog::setIdea(int index, std::string idea) {
    if (this->brain)
        this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    if (this->brain)
        return this->brain->getIdea(index);
    return "";
}