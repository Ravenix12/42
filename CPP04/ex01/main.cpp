/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:38:33 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:41:03 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
	//subject
	int y = 2; //has to be even
	Animal *animals[y];
	for (int x = 0; x < y/2; x++){
		animals[x] = new Dog();
	}
	for (int x = y/2; x < y; x++){
		animals[x] = new Cat();
	}
	for (int x = 0; x < y; x++){
		delete animals[x];
	}

	std::cout << "\n-----------\n\n";

	//provided
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;

	std::cout << "\n-----------\n\n";

	//check deep copy
	Cat *cat = new Cat();
	cat->setIdea(0, "I am a cat");
	Cat *newCat = new Cat(*cat);
	std::cout << newCat->getIdea(0) << std::endl;
	cat->setIdea(0, "Am I a cat?");
	std::cout << newCat->getIdea(0) << std::endl; //should be the same
	delete cat;
	std::cout << newCat->getIdea(0) << std::endl; //should exist as it is a deep copy
	delete newCat;
	
	return 0;
}