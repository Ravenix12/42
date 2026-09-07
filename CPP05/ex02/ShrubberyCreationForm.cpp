/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:30:35 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/07 21:14:31 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const int sign = 145;
const int exec = 137;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", sign, exec){
	std::cout << "ShrubberyCreationForm constructor called\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", sign, exec){
	this->target = target;
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destructor called\n";
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->target = other.target;
    return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &dup) : AForm(dup){
	std::cout << "ShrubberyCreationForm Copy constructor called\n";
}

