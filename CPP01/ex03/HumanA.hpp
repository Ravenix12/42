/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:12:35 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 15:15:33 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA{
	public: 
	void attack();
	HumanA(std::string name, Weapon weapon);
	~HumanA();
	
	private:
	std::string _name;
	Weapon	_weapon;
};

#endif