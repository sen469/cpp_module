/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:24:09 by ssawa             #+#    #+#             */
/*   Updated: 2026/03/16 19:00:49 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}


// int main()
// {
// 	// --- 1. MateriaSource のテスト ---
// 	std::cout << "--- 1. MateriaSource Test ---" << std::endl;
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	// 4つ以上学習させて満杯時の挙動を確認（溢れた分がリークしないか）
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	src->learnMateria(new Ice()); // 5つ目
//
// 	// --- 2. キャラクターの生成と装備 ---
// 	std::cout << "\n--- 2. Character Equip Test ---" << std::endl;
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
//
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	
// 	// 存在しないタイプを作成しようとした場合
// 	tmp = src->createMateria("unknown");
// 	me->equip(tmp); // NULLが渡されるはず
//
// 	// --- 3. 使用 (use) のテスト ---
// 	std::cout << "\n--- 3. Use Test ---" << std::endl;
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	me->use(2, *bob); // 空スロット（何も起きないはず）
// 	me->use(10, *bob); // 範囲外（何も起きないはず）
//
// 	// --- 4. 深いコピーのテスト ---
// 	std::cout << "\n--- 4. Deep Copy Test (Copy Constructor) ---" << std::endl;
// 	Character* original = new Character("original");
// 	original->equip(src->createMateria("ice"));
// 	
// 	Character* copy = new Character(*original); // コピーコンストラクタ
// 	std::cout << "Original name: " << original->getName() << std::endl;
// 	std::cout << "Copy name: "    << copy->getName() << std::endl;
// 	
// 	original->use(0, *bob);
// 	copy->use(0, *bob); // コピー側も同じ魔法を使えるか
// 	
// 	std::cout << "\n--- 5. Deep Copy Test (Assignment Operator) ---" << std::endl;
// 	Character* assignee = new Character("assignee");
// 	*assignee = *original; // 代入演算子
// 	assignee->use(0, *bob);
//
// 	// --- 6. unequip のテスト（Floor連結リストの検証） ---
// 	std::cout << "\n--- 6. Unequip Test ---" << std::endl;
// 	me->unequip(0); // スロット0のIceを外す（Floorへ）
// 	me->use(0, *bob); // 外したので何も起きないはず
// 	
// 	// 外した後に新しいのを装備
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	me->use(0, *bob); // 今度は Cure が発動するはず
//
// 	// --- 7. 解放 ---
// 	std::cout << "\n--- 7. Destruction Test ---" << std::endl;
// 	delete bob;
// 	delete me;
// 	delete src;
// 	delete original;
// 	delete copy;
// 	delete assignee;
//
// 	return (0);
// }
