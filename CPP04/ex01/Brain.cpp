/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:33:57 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/01 17:26:46 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called\n";
}
Brain::~Brain(){
	std::cout << "Brain destructor called\n";
}
Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; i++){
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
Brain::Brain(const Brain &dup)
{
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; i++)    {
        this->ideas[i] = dup.ideas[i];
    }
}

std::string Brain::getIdea(int i){
	return ideas[i];
}

void Brain::setIdea(int i, std::string idea){
	ideas[i] = idea;
}

