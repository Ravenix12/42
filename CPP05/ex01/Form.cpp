/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 22:02:26 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/17 21:20:33 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// def constructor needs to init all in const values in constructor -> form with highst scrutiny created
Form::Form() : name("Default"), signGrade(1), execGrade(1), isSigned(false) {
}
	
Form::Form(std::string name, int signGrade, int execGrade):name(name), signGrade(signGrade), execGrade(execGrade), isSigned(false){
	std::cout << "Form constructor called\n";
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}
Form::~Form(){
	std::cout << "Form destructor called\n";
}
Form &Form::operator=(const Form &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->isSigned = other.isSigned;
    return *this;
}
Form::Form(const Form &dup) : name(dup.name), signGrade(dup.signGrade), execGrade(dup.execGrade){
	std::cout << "Form Copy constructor called\n";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::string const Form::getName() const{
	return name;
}
bool Form::getIsSigned() const{
	return isSigned;
}
int Form::getSignGrade() const{
	return signGrade;
}
int Form::getExecGrade() const{
	return execGrade;
}

std::ostream& operator<<(std::ostream& os, const Form& b){
	os << "Form name: " << b.getName() << ", signGrade: " << b.getSignGrade() << ", execGrade: " << b.getExecGrade() << ". This form is " << (b.getIsSigned() ? "Signed" : "Unsigned");
	return os;
}

void Form::beSigned(Bureaucrat &bureaucrat){
	if (signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	isSigned = 1;
}

