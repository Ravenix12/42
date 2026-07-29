/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:38:33 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:47:49 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl; //wrong
	std::cout << i->getType() << " " << std::endl; //wrong
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	//Wrong animal tests
	const WrongAnimal *k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); // will not output the cat sound!
	return 0;
}