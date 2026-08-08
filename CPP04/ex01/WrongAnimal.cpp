/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:50:28 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:37:27 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "Default constructor called\n";
	type = "unknown";
}
WrongAnimal::WrongAnimal(std::string _type){
	std::cout << "Default constructor called\n";
	type = _type;
}
WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called\n";
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
        this->type = other.type;
    return *this;
}
WrongAnimal::WrongAnimal(const WrongAnimal &dup) : type(dup.type){
	std::cout << "Copy constructor called\n";
}

void WrongAnimal::makeSound() const{
	std::cout << "mysterious sounds...\n";
}

std::string WrongAnimal::getType() const{
	return type;
}
