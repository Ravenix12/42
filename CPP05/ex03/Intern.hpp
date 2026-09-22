/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:50:22 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/22 21:27:04 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "iostream"
#include "string"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern{
	public:
		Intern();
		~Intern();
		Intern &operator=(const Intern &other);
		Intern(const Intern &dup);

		AForm *makeForm(std::string name, std::string target);

	private:
        AForm *createShrubbery(std::string const &target);
        AForm *createRobotomy(std::string const &target);
        AForm *createPardon(std::string const &target);

		class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
	
};

#endif