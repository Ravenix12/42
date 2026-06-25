/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 09:52:52 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 11:32:20 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 5;
	Zombie *zombie = zombieHorde(N, "zombie");
	for (int i = 0; i < N; i++)
	{
		std::cout << i << " ";
		zombie[i].announce();
	}

	delete[] zombie;
}