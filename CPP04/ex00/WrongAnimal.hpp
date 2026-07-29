/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:51:08 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/29 21:30:25 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal{
	public :
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &other);
	WrongAnimal(const WrongAnimal &dup);

	void makeSound() const;
	std::string getType() const;

	protected:
	std::string type;
};

#endif


