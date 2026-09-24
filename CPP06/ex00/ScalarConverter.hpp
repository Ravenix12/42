/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 21:58:10 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/24 21:35:02 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &other);
        ScalarConverter &operator=(ScalarConverter const &other);
        ~ScalarConverter();

	public:
	static int convert(std::string const &literal);
};

void special(std::string const &literal);

#endif