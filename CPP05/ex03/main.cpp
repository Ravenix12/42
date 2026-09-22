/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:04:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/22 21:25:28 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someIntern;
    AForm *form = someIntern.makeForm("shrubbery creation", "garden");
    std::cout << *form << std::endl;
    delete form;

    try {
        someIntern.makeForm("nonexistent form", "target");
    } catch (std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}