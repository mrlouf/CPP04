/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:17:40 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 15:06:39 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{

/*
In your main function, create and fill an array of Animal objects. Half of it will
be Dog objects and the other half will be Cat objects. At the end of your program
execution, loop over this array and delete every Animal. You must delete directly dogs
and cats as Animals. The appropriate destructors must be called in the expected order.
Don’t forget to check for memory leaks.
A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies
are deep copies!
*/

	{
	const Animal* j = new Dog();
	const Animal* i = new Cat(); 

	delete j;//should not create a leak
	delete i;
	}

	{
	std::cout << std::endl;
	std::cout << "\033[1;31mBrain & ideas Test\033[0m" << std::endl;

	Cat *C = new Cat();

	std::cout << "C Idea 8 = \"" << C->getBrain()->getIdea(7) << "\"" << std::endl;

	C->getBrain()->setIdea("Meow", 7);
	std::cout << "Original Idea 8 = \"" << C->getBrain()->getIdea(7) << "\"" << std::endl;

	Cat Copy = *C;

	std::cout << "Copy Idea 8 = \"" << Copy.getBrain()->getIdea(7) << "\"" << std::endl;
	Copy.getBrain()->setIdea("MeowMeowww", 7);
	std::cout << "Copy Idea 8 changed" << std::endl;
	std::cout << "Copy Idea 8 = \"" << Copy.getBrain()->getIdea(7) << "\"" << std::endl;

	std::cout << "Original Idea 8 = \"" << C->getBrain()->getIdea(7) << "\"" << std::endl;
	delete C;
	}

	return 0;
}
