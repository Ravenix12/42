/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:33:16 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/13 18:39:39 by smariapp         ###   ########.fr       */
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
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &dup) : AForm(dup){
	std::cout << "RobotomyRequestForm Copy constructor called\n";
}

void RobotomyRequestForm::action() const {
	std::cout << " drrrrrrrrrrrrrrrrrrrr  drrrrrrrrrrrrrrrrrrrrrrr drrrrrrrrrrrrrrr";
	rand() % 2 ? std::cout << target << " has been robotomized successfully" : std::cout << target << " robotomy failed";
}
