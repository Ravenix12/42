/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:11:29 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/20 15:23:58 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : last(0), full(0)
{ }

std::string PhoneBook::fillField(std::string str)
{
	std::string entry;

	while (1)
	{
		std::cout << str;
		std::getline(std::cin, entry);
		if (entry.size() > 0)
			break;
		std::cout << "Invalid Name. Please input atleast 1 character\n";
	}
	return entry;
}

bool PhoneBook::isNumeric(const std::string str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void PhoneBook::writeName(std::string name)
{
	std::cout << "|";
	if (name.size() <= 10)
		std::cout << std::setw(10) << name;
	else
	{
		std::cout << name.substr(0, 9);
		std::cout << '.';
	}
}
void PhoneBook::addContact()
{
	std::string phoneNumber;
	std::string firstName = fillField("First Name     | ");
	std::string lastName = fillField("Last Name      | ");
	std::string nickname = fillField("Nickname       | ");
	while (1)
	{
		phoneNumber = fillField("Phone Number   | ");
		if (isNumeric(phoneNumber))
			break;
		std::cout << "Invalid input. Please enter numeric value.\n";
	}
	std::string darkestSecret = fillField("Darkest Secret | ");
	Contact newContact = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	contacts[last] = newContact;
	if (last < 7)
		last++;
	else
	{
		full = 1;
		last = 0;
	}
}

void PhoneBook::display()
{
	Contact contact;
	std::string entry;

	for (int i = 0; i < 8; i++)
	{
		contact = contacts[i];
		if (contact.get_isFilled() == false)
			break;
		std::cout << std::setw(10) << (i + 1);
		writeName(contact.get_fName());
		writeName(contact.get_lName());
		writeName(contact.get_nName());
		std::cout << '\n';
	}
}

void PhoneBook::searchContact()
{
	Contact contact;
	int ix;

	if (!full && last == 0)
	{
		std::cout << "No contacts in here, add some to view them\n";
		return;
	}
	display();
	ix = 9;
	while (1)
	{
		std::istringstream ss(fillField("Index > "));
		ss >> ix;
		if ((ix > 0 && ix < 9) && (full || ix <= (last + 1)))
			break;
		else
			std::cout << "Invalid input. Please enter a valid index\n";
	}
	contact = contacts[ix - 1];
	std::cout << "First Name     | " + contact.get_fName() << std::endl;
	std::cout << "Last Name      | " + contact.get_lName() << std::endl;
	std::cout << "Nickname       | " + contact.get_nName() << std::endl;
	std::cout << "Phone Number   | " + contact.get_pNum() << std::endl;
	std::cout << "Darkest secret | " + contact.get_dSec() << std::endl;
}
