/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:51:08 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:31:33 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	public :
	Dog();
	~Dog();
	Dog &operator=(const Dog &other);
	Dog(const Dog &dup);

	void makeSound() const;
	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;
	
	private:
	std::string type;
	Brain *brain;
};

#endif


