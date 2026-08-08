/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:38:33 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:45:50 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
	//should throw error when uncommented
	//Animal *animal = new Animal();

	//works
	Animal *dog = new Dog();
	delete dog;
	
	return 0;
}