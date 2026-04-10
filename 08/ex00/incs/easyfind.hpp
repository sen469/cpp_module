/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:14:52 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/06 18:26:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Error: Element not found in container.");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int target)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

template <typename T>
typename T::iterator easyfind(const T &container, int target)
{
	typename T::const_iterator	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif
