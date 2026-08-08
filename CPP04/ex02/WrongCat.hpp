/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 21:01:56 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:30:31 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public :
	WrongCat();
	~WrongCat();
	WrongCat &operator=(const WrongCat &other);
	WrongCat(const WrongCat &dup);

	void makeSound() const;

	private:
		std::string type;
};

#endif