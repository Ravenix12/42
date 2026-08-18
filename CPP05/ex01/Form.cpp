/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 22:02:26 by smariapp          #+#    #+#             */
/*   Updated: 2026/08/18 22:17:50 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::string const Form::getName(){
	return name;
}
bool Form::getIsSigned(){
	return isSigned;
}
int const Form::getSignGrade(){
	return signGrade;
}
int const Form::getExecGrade(){
	return execGrade;
}