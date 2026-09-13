/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:30:35 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/13 18:38:50 by smariapp         ###   ########.fr       */
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
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &dup) : AForm(dup){
	std::cout << "ShrubberyCreationForm Copy constructor called\n";
}

void ShrubberyCreationForm::action() const {
    std::string filename = target + "_shrubbery.txt";
    std::ofstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cout << "Could not create shrubbery file for " << target << std::endl;
        return ;
    }

    file << "        &&&&&&&&\n"
         << "     &&&&&&&&&&&&&&\n"
         << "   &&&&o&&&&&&&&&&&&&\n"
         << " &&&&&&oo&&&&&&&&&&&&&&\n"
         << "&&&&&&&&&&&&&&&&&&o&&&&&\n"
         << "  &&&&&&&&&&&&&&&o&&&&\n"
         << "     &&&&&&&&&&&&&&\n"
         << "        &&&&&&&&\n"
         << "           ||\n"
         << "           ||\n"
         << "         ~~~~~~~\n";

    file.close();
}


