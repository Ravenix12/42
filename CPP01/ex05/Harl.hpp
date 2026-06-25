/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:17:31 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/25 17:30:35 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Harl{
	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	public:
	void complain( std::string level );
	Harl();
	~Harl();
};