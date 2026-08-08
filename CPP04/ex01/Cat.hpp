/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 21:01:56 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:32:21 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	public :
	Cat();
	~Cat();
	Cat &operator=(const Cat &other);
	Cat(const Cat &dup);

	void makeSound() const;
	void setIdea(int index, std::string idea);
	std::string getIdea(int index) const;

	private:
	std::string type;
	Brain *brain;
};

#endif