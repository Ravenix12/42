/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:46:14 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/30 21:31:22 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed &dup) {
	std::cout << "Copy constructor called\n";
	raw = dup.getRawBits();
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
    if (this != &other)
        raw = other.getRawBits();
    return *this;
}
Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}
int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return raw;
}
void Fixed::setRawBits(int const raw){
	this->raw = raw;
}
