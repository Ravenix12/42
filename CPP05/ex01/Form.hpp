/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 22:02:36 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/18 22:15:44 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Form{
	public:

	class GradeTooHighException : public std::exception{
		public:
        const char* what() const throw();	
	};
	
	class GradeTooLowException : public std::exception{
		public:
		const char* what() const throw();
	};

	std::string const getName();
	bool getIsSigned();
	int const getSignGrade();
	int const getExecGrade();	
	
	private:
	std::string const name;
	bool isSigned;
	int const signGrade;
	int const execGrade;
	
};


#endif