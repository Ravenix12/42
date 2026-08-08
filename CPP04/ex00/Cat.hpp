/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 21:01:56 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 16:47:50 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal{
	public :
	Cat();
	~Cat();
	Cat &operator=(const Cat &other);
	Cat(const Cat &dup);

	void makeSound() const;

	private:
		std::string type;
};

#endif