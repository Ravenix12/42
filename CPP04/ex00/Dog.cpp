/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:50:13 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:45:30 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog constructor called\n";
	type = "Dog";
}
Dog::~Dog(){
	std::cout << "Dog " << type << " destructor called\n";
}
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
        this->type = other.type;
    return *this;
}
Dog::Dog(const Dog &dup) : type(dup.type){
		std::cout << "Copy constructor called\n";
}

void Dog::makeSound() const{
	std::cout << "woof woof\n";
}