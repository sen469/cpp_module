/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:30:37 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/10 16:17:17 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	public:
		// Constructors
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		// Destructors
		~Array();
		// Overloaded Operators
		Array	&operator=(const Array &other);
		T		&operator[](unsigned int index);
		const T	&operator[](unsigned int index) const;
		// Getter
		unsigned int	size() const;

	private:
		T				*arr;
		unsigned int	sz;
};

template <typename T>
Array<T>::Array(): arr(NULL), sz(0) { }

template <typename T>
Array<T>::Array(unsigned int n) : sz(n)
{
	if (n == 0)
		this->arr = NULL;
	else
		this->arr = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : arr(NULL), sz(0)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		T	*new_arr;

		if (other.size() > 0)
			new_arr = new T[other.size()];
		else
			new_arr = NULL;
		for (unsigned int i = 0; i < other.size(); i++)
			new_arr[i] = other.arr[i];
		delete[] this->arr;
		this->arr = new_arr;
		this->sz = other.size();
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->arr)
		delete[] this->arr;
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= this->size() || this->arr == NULL)
		throw std::exception();
	return (this->arr[index]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= this->size() || this->arr == NULL)
		throw std::exception();
	return (this->arr[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->sz);
}

#endif
