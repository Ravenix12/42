/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:50:20 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:37:38 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat"){
	std::cout << "Cat constructor called\n";
	brain = new Brain();
}
Cat::~Cat(){
	delete brain;
	std::cout << "Cat destructor called\n";
}
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
        this->type = other.type;
    return *this;
}
Cat::Cat(const Cat &dup) : Animal(dup){
	std::cout << "Cat Copy constructor called\n";
	this->brain = new Brain(*dup.brain);
}

void Cat::makeSound() const{
	std::cout << "meow meow\n";
}

void Cat::setIdea(int index, std::string idea) {
    if (this->brain)
        this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    if (this->brain)
        return this->brain->getIdea(index);
    return "";
}