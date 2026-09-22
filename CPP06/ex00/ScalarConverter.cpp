/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 21:58:05 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/22 22:08:17 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &other) { 
	(void)other; 
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) { 
	(void)other; 
	return *this; 
}
ScalarConverter::~ScalarConverter() {}

int ScalarConverter::convert(std::string) {
	
}


