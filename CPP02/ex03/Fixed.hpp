/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shivani <shivani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:46:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/07/11 15:27:37 by shivani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed{
	public:
	Fixed();
	Fixed(const Fixed &dup);
	
	Fixed(const int raw);
	Fixed(const float value);
	
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator>(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);

	float operator+(const Fixed &other);
	float operator-(const Fixed &other);
	float operator*(const Fixed &other);
	float operator/(const Fixed &other);

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	private:
		int raw;
		static const int fractionalBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif