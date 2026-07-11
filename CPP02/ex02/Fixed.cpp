/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:46:14 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/11 15:29:40 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;
Fixed::Fixed() : raw(0) {
	//std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed &dup) {
	//std::cout << "Copy constructor called\n";
	//raw = dup.getRawBits();
	*this = dup;
}
Fixed::Fixed(const int raw){
	//std::cout << "Int constructor called\n";
	this->raw = raw << fractionalBits;
}
Fixed::Fixed(const float value){
	//std::cout << "Float constructor called\n";
	raw = roundf(value * (1 << fractionalBits));
}
Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called\n";
    if (this != &other)
        raw = other.getRawBits();
    return *this;
}
Fixed::~Fixed() {
	//std::cout << "Destructor called\n";
}
int Fixed::getRawBits(void) const{
	//std::cout << "getRawBits member function called\n";
	return raw;
}
void Fixed::setRawBits(int const raw){
	this->raw = raw;
}

float Fixed::toFloat( void ) const{
	return ((float)raw / (float)(1 << fractionalBits));
}

int Fixed::toInt( void ) const{
	return (raw >> fractionalBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

bool Fixed::operator>(const Fixed &other){
    return (raw > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other){
    return (raw < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other){
    return (raw >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other){
    return (raw <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other){
    return (raw == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other){
    return (raw != other.getRawBits());
}

float Fixed::operator+(const Fixed &other){
	return (this->toFloat() + other.toFloat());
}
float Fixed::operator-(const Fixed &other){
	return (this->toFloat() - other.toFloat());
}
float Fixed::operator*(const Fixed &other){
	return (this->toFloat() * other.toFloat());	
}
float Fixed::operator/(const Fixed &other){
	return (this->toFloat() / other.toFloat());	
}

Fixed	Fixed::operator++(){
	raw++;
	return (*this);
}

Fixed	Fixed::operator--(){
	raw--;
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed tmp = *this;
	++raw;
	return (tmp);
}

Fixed	Fixed::operator--(int){
	Fixed tmp = *this;
	--raw;
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return (a);
	return (b);	
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}





