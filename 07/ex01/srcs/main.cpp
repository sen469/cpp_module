/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:27:09 by ssawa             #+#    #+#             */
/*   Updated: 2026/04/05 17:28:23 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// 1行のコメントアウトを使用
// 非const参照を取る関数（値を書き換える）
template <typename T>
void increment(T & n)
{
	n++;
}

// const参照を取る関数（値を表示するだけ）
template <typename T>
void print_element(const T & n)
{
	std::cout << n << " ";
}

int main()
{
	// 1. int配列のテスト
	int arr[] = {0, 1, 2, 3, 4};
	std::size_t len = 5;

	std::cout << "Original int array: ";
	::iter(arr, len, print_element<int>);
	std::cout << std::endl;

	// インクリメント処理（非const参照が必要）
	::iter(arr, len, increment<int>);

	std::cout << "Incremented:       ";
	::iter(arr, len, print_element<int>);
	std::cout << std::endl;

	// 2. constな配列のテスト
	const std::string strs[] = {"Hello", "42", "Tokyo"};
	
	std::cout << "Const string array: ";
	// constな配列なので、引数が const T& の関数しか渡せない
	::iter(strs, 3, print_element<std::string>);
	std::cout << std::endl;

	return 0;
}
