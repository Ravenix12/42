/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:35:14 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/07 21:26:56 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int sign = 25;
const int exec = 5;

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", sign, exec){
	std::cout << "PresidentialPardonForm constructor called\n";
}
PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", sign, exec){
	this->target = target;
	std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destructor called\n";
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->target = other.target;
    return *this;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &dup) : AForm(dup){
	std::cout << "PresidentialPardonForm Copy constructor called\n";
}