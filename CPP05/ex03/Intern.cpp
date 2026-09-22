/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:50:26 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/22 21:41:10 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Intern constructor called\n";
}
Intern::~Intern(){
	std::cout << "Intern destructor called\n";
}
Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Copy assignment operator called\n";
	(void) other;
    return *this;
}
Intern::Intern(const Intern &dup){
	(void) dup;
	std::cout << "Intern Copy constructor called\n";
}

void lowercase(std::string &str){
	for (unsigned int i = 0; i < str.length(); ++i)	{
		str[i] = tolower(str[i]);
	}
}

AForm *Intern::createShrubbery(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "unknown form";
}

AForm *Intern::makeForm(std::string name, std::string target){
	std::string forms[3] =  {"presidential pardon", "presidential pardon", "shrubbery creation"};
	lowercase(name);

	AForm *(Intern::*formCreators[3])(std::string const &) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (forms[i].compare(name) == 0)
        {
            AForm *form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << name << " form" << std::endl;
            return form;
        }
    }

    throw Intern::FormNotFoundException();
	
}