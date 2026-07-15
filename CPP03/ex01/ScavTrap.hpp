/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 19:29:57 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/15 12:49:17 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap: public ClapTrap {
	public:
	ScavTrap();
	ScavTrap(std::string Name);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &other);
	ScavTrap(const ScavTrap &dup);
	void attack(const std::string &target);
	void guardGate();
};

#endif