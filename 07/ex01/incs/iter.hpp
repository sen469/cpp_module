/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:17:43 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/05 17:28:17 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// void	iter(T *arr, const size_t len, void	(*func)(T &))
template <typename T, typename F>
void	iter(T *arr, const size_t len, F func)
{
	if (!arr || !func)
		return;
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif
