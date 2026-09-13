/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:04:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/13 18:44:37 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

void test_signing(int bgrade, int sgrade)
{
	Bureaucrat Y("Y", bgrade);
	PresidentialPardonForm Z("Zaphod"); // sign=25, exec=5, fixed grades

	(void)sgrade; // grades are now fixed per concrete form, not passed in
	try
	{
		Y.signForm(Z);
		std::cout << Y << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Can't sign: " << e.what() << std::endl;
	}
}

void test_execute_unsigned(int bgrade)
{
	std::cout << "-- test_execute_unsigned(" << bgrade << ") --\n";
	Bureaucrat Y("Y", bgrade);
	PresidentialPardonForm form("Alice"); // not signed yet

	try
	{
		Y.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}

void test_execute_grade_too_low(int bgrade)
{
	std::cout << "-- test_execute_grade_too_low(" << bgrade << ") --\n";
	Bureaucrat Y("Y", bgrade);
	PresidentialPardonForm form("Bob");

	try
	{
		Y.signForm(form);   // sign requires grade <= 25
		Y.executeForm(form); // execute requires grade <= 5
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}

void test_execute_success_pardon()
{
	std::cout << "-- test_execute_success_pardon --\n";
	Bureaucrat Y("Y", 1); // highest possible grade
	PresidentialPardonForm form("Carol");

	try
	{
		Y.signForm(form);
		Y.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}

void test_execute_success_robotomy()
{
	std::cout << "-- test_execute_success_robotomy (run few times to see 72% chance) --\n";
	Bureaucrat Y("Y", 1);
	RobotomyRequestForm form("Toaster");

	try
	{
		Y.signForm(form);
		for (int i = 0; i < 5; i++)
			Y.executeForm(form); // call multiple times to observe randomness
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}

void test_execute_success_shrubbery()
{
	std::cout << "-- test_execute_success_shrubbery --\n";
	Bureaucrat Y("Y", 1);
	ShrubberyCreationForm form("garden");

	try
	{
		Y.signForm(form);
		Y.executeForm(form); // should create garden_shrubbery.txt
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
}

void test_execute_polymorphic_array()
{
	std::cout << "-- test_execute_polymorphic_array --\n";
	Bureaucrat Y("Y", 1);

	AForm* forms[3];
	forms[0] = new ShrubberyCreationForm("polyGarden");
	forms[1] = new RobotomyRequestForm("polyToaster");
	forms[2] = new PresidentialPardonForm("polyDave");

	for (int i = 0; i < 3; i++)
	{
		try
		{
			Y.signForm(*forms[i]);
			Y.executeForm(*forms[i]);
		}
		catch (const std::exception& e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
		delete forms[i];
	}
}

int main()
{
	test_signing(1, 25);   // pass, grade high enough
	test_signing(150, 25); // fail, grade too low

	std::cout << "\n-----------------------\n\n";

	test_execute_unsigned(1);        // should throw FormNotSignedException
	test_execute_grade_too_low(20);  // signs fine (20<=25), fails execute (20>5)
	test_execute_success_pardon();
	test_execute_success_robotomy();
	test_execute_success_shrubbery();

	std::cout << "\n-----------------------\n\n";

	test_execute_polymorphic_array(); // tests dynamic dispatch through AForm*

	return 0;
}