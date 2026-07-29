/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:38:52 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:42:04 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal constructor called\n";
	type = "unknown";
}
Animal::~Animal(){
	std::cout << "Animal " << type << " destructor called\n";
}
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
        this->type = other.type;
    return *this;
}
Animal::Animal(const Animal &dup) : type(dup.type){
	std::cout << "Copy constructor called\n";
}

void Animal::makeSound() const{
	std::cout << "mysterious sounds...\n";
}

std::string Animal::getType() const{
	return type;
}
