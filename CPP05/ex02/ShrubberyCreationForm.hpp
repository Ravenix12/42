/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:30:43 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/07 21:23:07 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const ShrubberyCreationForm &dup);
	
	void execute(ShrubberyCreationForm const &executor) const;
	
	private:
	std::string target;
};

#endif