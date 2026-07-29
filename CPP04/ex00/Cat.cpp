/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:50:20 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:45:38 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat constructor called\n";
	type = "Cat";
}
Cat::~Cat(){
	std::cout << "Cat " << type << " destructor called\n";
}
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
        this->type = other.type;
    return *this;
}
Cat::Cat(const Cat &dup) : type(dup.type){
		std::cout << "Copy constructor called\n";
}

void Cat::makeSound() const{
	std::cout << "meow meow\n";
}