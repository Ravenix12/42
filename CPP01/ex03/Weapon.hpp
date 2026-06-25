/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:12:24 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 15:13:39 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon{
	public:
	std::string getType();
	void setType(std::string type);
	Weapon();
	Weapon(std::string type);
	~Weapon();
	
	private:
	std::string _type;
};

#endif