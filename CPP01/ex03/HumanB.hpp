/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:12:29 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 15:15:40 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
	public: 
	void attack();
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);

	private:
	std::string _name;
	Weapon	*_weapon;
};

#endif