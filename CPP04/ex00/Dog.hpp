/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:51:08 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:45:25 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal{
	public :
	Dog();
	~Dog();
	Dog &operator=(const Dog &other);
	Dog(const Dog &dup);

	void makeSound() const;

	private:
		std::string type;
};

#endif


