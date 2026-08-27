/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 22:02:26 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/27 22:03:24 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// def constructor needs to init all in const values in constructor -> form with highst scrutiny created
AForm::AForm() : name("Default"), signGrade(1), execGrade(1) {
}
	
AForm::AForm(std::string name, int signGrade, int execGrade):name(name), signGrade(signGrade), execGrade(execGrade){
	std::cout << "Form constructor called\n";
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}
AForm::~AForm(){
	std::cout << "Form destructor called\n";
}
AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->isSigned = other.isSigned;
    return *this;
}
AForm::AForm(const AForm &dup) : name(dup.name), signGrade(dup.signGrade), execGrade(dup.execGrade){
	std::cout << "Form Copy constructor called\n";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::string const AForm::getName() const{
	return name;
}
bool AForm::getIsSigned() const{
	return isSigned;
}
int AForm::getSignGrade() const{
	return signGrade;
}
int AForm::getExecGrade() const{
	return execGrade;
}

std::ostream& operator<<(std::ostream& os, const Form& b){
	os << "Form name: " << b.getName() << ", signGrade: " << b.getSignGrade() << ", execGrade: " << b.getExecGrade() << ". This form is " << (b.getIsSigned() ? "Signed" : "Unsigned");
	return os;
}

void AForm::beSigned(Bureaucrat &bureaucrat){
	if (signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	isSigned = 1;
}

bool AForm::canBeExecutedBy(Bureaucrat const &executor) const {
	return (executor.getGrade() <= execGrade);
}


