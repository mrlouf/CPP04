/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:36:18 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 15:47:10 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/MateriaSource.hpp"
#include "inc/Character.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"

int main()
{
	{
		std::cout << "\033[31mSubject's test\033[0m\n" << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\n\033[31mFull MateriaSource\033[0m\n" << std::endl;

		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());	// MateriaSource is full of Ice
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\n\033[31mUsing non-equipped Materia\033[0m\n" << std::endl;

		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());	// Ice learned but not created/equipped
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\n\033[31mUnequipping Materia\033[0m\n" << std::endl;

		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		me->unequip(0);	// Unequip Cure
		me->use(0, *bob); // Cure is unequipped and cannot be used

		delete bob;
		delete me;
		delete src;
	}

	return 0;
}
