/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:33:16 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/07 21:23:39 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const int sign = 72;
const int exec = 45;

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", sign, exec){
	std::cout << "RobotomyRequestForm constructor called\n";
}
RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", sign, exec){
	this->target = target;
	std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor called\n";
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->target = other.target;
    return *this;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &dup) : AForm(dup){
	std::cout << "RobotomyRequestForm Copy constructor called\n";
}