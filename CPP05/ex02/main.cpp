/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:04:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/19 22:06:53 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test_initialise(int sgrade, int egrade){
	try {
		Form X("X", sgrade, egrade);
		std::cout << X << std::endl;
	}
	catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

void test_signing(int bgrade, int sgrade){
	Bureaucrat Y("Y", bgrade);
	Form Z("Z", sgrade, 1);
	try {
		Y.signForm(Z);
	}
	catch (const std::exception& e) {
        //std::cout << "Can't sign: " << e.what() << std::endl;
    }
}

int main(){
	test_initialise(150,1);
	test_initialise(151, 0);
	std::cout << "\n-----------------------\n\n";
	test_signing(1,1); //pass
	test_signing(150,1); //fail
	test_signing(1,150); //pass

	
	return 0;
}