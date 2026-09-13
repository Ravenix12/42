/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:35:19 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/13 18:39:48 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm {
	public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	RobotomyRequestForm(const RobotomyRequestForm &dup);
	
	void action() const;
	
	private:
	std::string target;
};

#endif