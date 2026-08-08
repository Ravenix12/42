/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:34:04 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:25:47 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"
#include "string"

class Brain{
	private:
	std::string ideas[100];

	public:
	Brain();
	virtual ~Brain();
	Brain &operator=(const Brain &other);
	Brain(const Brain &dup);
	std::string getIdea(int i);
	void setIdea(int i, std::string idea);
};

#endif
