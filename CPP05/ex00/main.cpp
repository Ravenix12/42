/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:04:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/18 22:00:54 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test_initialise(int grade){
	try {
		Bureaucrat X("X", grade);
		std::cout << "Introducing " << X << std::endl;
	}
	catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

void test_increase(int grade){
	Bureaucrat Y("Y", grade);
	try {
	Y.increaseGrade();
	std::cout << Y << std::endl;
	}
	catch (const std::exception& e) {
        std::cout << "Can't increase: " << e.what() << std::endl;
    }
}

void test_decrease(int grade){
	Bureaucrat Z("Z", grade);
	try {
	Z.decreaseGrade();
	std::cout << Z << std::endl;
	}
	catch (const std::exception& e) {
        std::cout << "Can't decrease: " << e.what() << std::endl;
    }
}

int main(){
	test_initialise(1);
	test_initialise(150);
	test_initialise(151);
	test_initialise(0);
	std::cout << "\n-----------------------\n\n";
	test_increase(1);
	test_increase(150);
	std::cout << "\n-----------------------\n\n";
	test_decrease(1);
	test_decrease(150);
	
	return 0;
}