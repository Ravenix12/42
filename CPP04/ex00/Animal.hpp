/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:51:08 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:44:40 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{
	public :
	Animal();
	~Animal();
	Animal &operator=(const Animal &other);
	Animal(const Animal &dup);

	virtual void makeSound() const;
	std::string getType() const;

	protected:
	std::string type;
};

#endif


