/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 21:36:20 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/13 18:36:54 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENIALPARDONFORM_HPP
#define PRESIDENIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	PresidentialPardonForm(const PresidentialPardonForm &dup);
	
	void action() const;
	private:
	std::string target;
};
#endif