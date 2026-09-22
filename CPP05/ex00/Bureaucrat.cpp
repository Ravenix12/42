/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:02:37 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/22 20:42:22 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	std::cout << "Bureaucrat constructor called\n";
}
Bureaucrat::Bureaucrat(std::string name, int grade):name(name), grade(grade){
	std::cout << "Bureaucrat constructor called\n";
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called\n";
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->grade = other.grade;
    return *this;
}
Bureaucrat::Bureaucrat(const Bureaucrat &dup) : name(dup.name), grade(dup.grade){
	std::cout << "Bureaucrat Copy constructor called\n";
}

std::string const Bureaucrat::getName() const{
	return name;
}
int Bureaucrat::getGrade() const{
	return grade;
}
void Bureaucrat::increaseGrade(){
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}
void Bureaucrat::decreaseGrade(){
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade is too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (o);
}
