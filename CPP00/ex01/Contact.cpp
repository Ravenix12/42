/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:11:42 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/20 14:40:10 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fName, std::string lName, std::string nName, std::string pNum, std::string dSec)
 : isFilled(true), firstName(fName), lastName(lName), nickname(nName), phoneNum(pNum), darkestSecret(dSec)
 {	}

std::string Contact::get_fName()
{
	return firstName;
}

std::string Contact::get_lName()
{
	return lastName;
}

std::string Contact::get_nName()
{
	return nickname;
}

std::string Contact::get_pNum()
{
	return phoneNum;
}

std::string Contact::get_dSec()
{
	return darkestSecret;
}

bool Contact::get_isFilled()
{
	return isFilled;
}


Contact::Contact()
 : isFilled(false)
 { }


