/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:46:12 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/30 21:35:20 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

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
	
	private:
		int raw;
		static const int fractionalBits = 8;
		//add insertion overload
};

#endif