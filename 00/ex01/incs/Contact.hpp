/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:27:39 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/28 15:22:27 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_darkest_secret;
		void		print_format(std::string str);
		void		print_format(int id);

	public:
		void	set_information(std::string f_name, \
						std::string l_name, \
						std::string n_name, \
						std::string p_number, \
						std::string d_secret);
		void	print_row(int id);
		void	print_person(void);
};

#endif
