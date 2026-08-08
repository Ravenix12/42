/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:51:08 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:42:45 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{
	public :
	Animal();
	Animal(std::string _type);
	virtual ~Animal();
	Animal &operator=(const Animal &other);
	Animal(const Animal &dup);

	virtual void makeSound() const = 0;
	std::string getType() const;

	protected:
	std::string type;
};

#endif


