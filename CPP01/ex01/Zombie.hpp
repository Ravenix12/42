/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 09:53:17 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 11:25:01 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	public:
	Zombie(std::string name);
	Zombie( void );
	~Zombie();
	void announce( void );
	void setName(std::string zombName);


	private:
	std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
