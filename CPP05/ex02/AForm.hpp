/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 22:02:36 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/27 21:57:38 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	public:

	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	~AForm();
	AForm &operator=(const AForm &other);
	AForm(const AForm &dup);

	class GradeTooHighException : public std::exception{
		public:
        const char* what() const throw();	
	};
	
	class GradeTooLowException : public std::exception{
		public:
		const char* what() const throw();
	};

	std::string const getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;	

	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
	bool canBeExecutedBy(Bureaucrat const &executor) const;	
	private:
	std::string const name;
	bool isSigned;
	int const signGrade;
	int const execGrade;
	
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif