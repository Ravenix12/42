/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 22:02:36 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/19 22:10:22 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	public:

	Form();
	Form(std::string name, int signGrade, int execGrade);
	~Form();
	Form &operator=(const Form &other);
	Form(const Form &dup);

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
		
	private:
	std::string const name;
	bool isSigned;
	int const signGrade;
	int const execGrade;
	
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif