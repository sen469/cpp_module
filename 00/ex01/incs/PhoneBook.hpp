/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:26:57 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/28 15:27:25 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


# define MAX_ID 8
# define MAX_LENGTH 10

# include "Contact.hpp"

class PhoneBook
{
	private:
		int		_top;
		int		_count;
		Contact	_contact[MAX_ID];
		void	print_separator(void);
		void	print_header(void);

	public:
		PhoneBook(void);
		void	addContact(const Contact &c);
		void	show_all(void);
		int		show_person(int idx);
		int		get_count(void);
};

#endif
