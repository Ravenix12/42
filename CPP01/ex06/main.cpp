/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 15:18:03 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/30 20:40:52 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Insufficient/Extra arguments. Try ./harlFilter \"LEVEL\"\n";
		return 1;
	}
	Harl harl = Harl();
	harl.complain(argv[1]);
	return 0;
}