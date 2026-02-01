/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:06:46 by ssawa             #+#    #+#             */
/*   Updated: 2026/01/28 15:24:25 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

int	ft_atoi(std::string s)
{
	int	ret;

	ret = 0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		ret *= 10;
		ret += (int)(s[i] - '0');
	}
	return (ret);
}

bool	is_nbr(const std::string s)
{
	if (s.empty())
		return (false);
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}
