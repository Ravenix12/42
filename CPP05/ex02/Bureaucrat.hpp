/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:02:30 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/13 18:37:48 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat{
	public:
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &other);
	Bureaucrat(const Bureaucrat &dup);

	std::string const getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();

	void signForm(AForm &form);
	void executeForm(AForm const & form) const;
	
	private:
	std::string const name;
	int grade;

	class GradeTooHighException : public std::exception{
		public:
        const char* what() const throw();	
	};
	class GradeTooLowException : public std::exception{
		public:
        const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif