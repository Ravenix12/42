/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 20:13:07 by smariapp          #+#    #+#             */
/*   Updated: 2026/06/20 15:14:44 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <sstream>

class PhoneBook {
	public:
		void	addContact();
		void	searchContact();
		PhoneBook();

	private:
		Contact		contacts[8];
		int 		last;
		int			full;
		std::string fillField(std::string str);
		bool 		isNumeric(const std::string str);
		void		writeName(std::string name);
		void		display();
};
