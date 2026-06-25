/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 10:44:58 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 11:25:40 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieHorde;
	
	zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].setName(name);
	}
	return (zombieHorde);
}