/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 21:58:05 by smariapp          #+#    #+#             */
/*   Updated: 2026/09/24 22:01:41 by smariapp         ###   ########.fr       */
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

static int convert(std::string const &literal){
	bool isVisibleChar = false;

	if (literal.size() == 1 && ((literal[0] >= 33 && literal[0] <= 126)))
		isVisibleChar = true;

	if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan" || literal == "inff" || literal == "+inff" || literal == "-inff" || literal == "nanf")
		special(literal);

	
}

bool isDigit(std::string const &literal)
{
	size_t ssize = literal.size();

	if (ssize == 1 && literal[0] >= '0' && literal[0] <= '9')
		return true;
	return false;
}
//1: digit, 2: visible 3:invisible 0:invalid 
int isChar(std::string const &literal)
{
	size_t ssize = literal.size();

	if (isDigit)
		return 1;
	if (ssize == 3 && literal[0] == (const char)"\'" && literal[2] == (const char)"\'")
	{
		if (literal[1] >= 32 && literal[1] <= 126)
			return 2;
		return 3;
	}
	return 0;
}

int isInt(std::string const &literal)
{
	int i;
	size_t ssize = literal.size();

	
	
}

void special(std::string const &literal)
{
	size_t ssize = literal.size();
	std::string fLiteral;
	std::string dLiteral;

	if (literal == "inff" || literal == "+inff" || literal == "-inff" || literal == "nanf") {
		fLiteral = literal;
		dLiteral = literal;
		dLiteral.erase(ssize - 1);
	}
	else {
		fLiteral = literal + 'f';
		dLiteral = literal;
	}
	std::cout << "char: impossible\nint: impossible\nfloat: " << fLiteral << "\ndouble: " << dLiteral << std::endl;
}


