/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 20:13:49 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/20 14:47:58 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact{
	public:
		std::string get_fName();
		std::string get_lName();
		std::string get_nName();
		std::string get_pNum();
		std::string get_dSec();
		bool get_isFilled();
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNum, std::string darkestSecret);
		Contact();
		
	private:
		bool isFilled;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string	phoneNum;
		std::string darkestSecret;
};