/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:11:42 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/17 21:06:04 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string	phoneNum;
		std::string darkestSecret;
		bool is_filled;

		Contact() : is_filled(false) {
		}
};