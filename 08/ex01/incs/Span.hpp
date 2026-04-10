/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:29:45 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/09 02:01:49 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
	public:
		// Constructors
		Span(unsigned int n);
		Span(const Span &other);

		// Destructors
		~Span();

		// Overloaded Operators
		Span	&operator=(const Span &other);

		// Getter
		unsigned int	size() const;

		// Setter

		// Other Functions
		void			addNumber(int n);
		unsigned int	longestSpan() const;
		unsigned int	shortestSpan() const;

	private:
		Span();
		unsigned int		get_maxsize() const;
		unsigned int		_max_size;
		std::vector<int>	_v;

};

#endif
