/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smariapp <smariapp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:37:14 by smariapp          #+#    #+#             */
/*   Updated: 2026/03/14 17:16:16 by smariapp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	argv++;
	while (*argv) {
		std::string s = *argv;
		for (int i = 0; i < (int)s.size(); i++) {
			s[i] = std::toupper(s[i]);
		}
		std::cout << s;
		argv++;
		if (*argv)
			std::cout << " ";
		else
			std::cout << "\n";
	}
	return 0;
}

