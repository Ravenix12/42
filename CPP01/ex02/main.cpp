/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:33:33 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 12:08:20 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "memory address of the string variable: " << &string <<std::endl;
	std::cout << "memory address held by stringPTR: " << stringPTR <<std::endl;
	std::cout << "memory address held by stringREF: " << &stringREF <<std::endl;

	std::cout << "value of the string variable: " << string <<std::endl;
	std::cout << "value pointed to by stringPTR: " << *stringPTR <<std::endl;
	std::cout << "value pointed to by stringREF: " << stringREF <<std::endl;
}