/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:14:40 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/20 15:08:39 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

int main(void) {
	std::string prompt;
	PhoneBook PB;
	
	std::cout << "Welcome to the PhoneBoook. Type ADD, SEARCH or EXIT.\n";
	while (1) {
		std::cout << "> ";
		if (!std::getline(std::cin, prompt))
		{
			std::cout << std::endl;
			break;
		}
		if (!prompt.compare("EXIT"))
			break;
		else if (!prompt.compare("ADD"))
			PB.addContact();
		else if (!prompt.compare("SEARCH"))
			PB.searchContact();
	}
	return 0;
}