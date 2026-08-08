/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:50:31 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:29:18 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << "WrongCat constructor called\n";
	type = "WrongCat";
}
WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called\n";
}
WrongCat &WrongCat::operator=(const WrongCat &other){
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
        this->type = other.type;
    return *this;
}
WrongCat::WrongCat(const WrongCat &dup) : WrongAnimal(dup){
		std::cout << "Copy constructor called\n";
}

void WrongCat::makeSound() const{
	std::cout << "meow meow\n";
}