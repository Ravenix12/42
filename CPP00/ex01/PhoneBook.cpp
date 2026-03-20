/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:11:29 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/17 21:09:08 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.cpp"
#include <string>

class PhoneBook {
	private:
		Contact contacts[8];

		std::string fillField(std::string str)
		{
			std::cout << str;
			std::string entry;			
			std::cin >> entry;
			return entry;
		}

		bool isNumeric(const std::string str)
		{
			for (int i = 0; i < (int)str.size(); i++)
			{
				if (!std::isdigit(str[i]))
					return false;
			}
			return true;
		}

	public:
		int last;

		void addContact()
		{
			Contact 	newContact;
			std::string	phoneNumber;

			newContact.firstName = fillField("First Name: ");
			newContact.lastName = fillField("Last Name: ");
			newContact.nickname = fillField("Nickname: ");
			while (1) {
				phoneNumber = fillField("Phone Number: ");
				if (isNumeric(phoneNumber)) {
					newContact.phoneNum = phoneNumber;
					break;
				}
				std::cout << "Invalid input. Please enter numeric value.\n";
			}
			newContact.darkestSecret = fillField("Darkest Secret: ");
			newContact.is_filled = true;

			contacts[last] = newContact;
			if (last < 7)
				last++;
			else
				last = 0;		
		}

		void	display()
		{
			Contact 	contact;
			std::string	entry;
			for (int i = 0; i < 8; i++)
			{
				contact = contacts[i];
				if (contact.is_filled == false)
					break;
				std::cout << (i + 1);
				std::cout << "         |";
				//CONTINUE HERE
				entry = contact.firstName;
				std::cout << "\n";
			}
		}
};

int main(void) {
	std::string prompt;
	PhoneBook PB;
	
	PB.last = 0;
	while (1) {
		std::cout << "> ";
		std::cin >> prompt;
		if (!prompt.compare("EXIT"))
			break;
		else if (!prompt.compare("ADD"))
			PB.addContact();
		else if (!prompt.compare("SEARCH"))
			PB.display();
	}
	return 0;
}