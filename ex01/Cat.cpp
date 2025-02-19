/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:22:31 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 14:56:47 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	_brain = new Brain;

	std::cout << type << " constructed" << std::endl;
}

Cat::Cat(const Cat &other) : Animal() {
    std::cout << type << " copy constructed" << std::endl;
	type = other.type;
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        type = other.type;
        delete _brain; // Delete existing _brain
        _brain = new Brain(*other._brain); // Deep copy of _brain
    }
    return *this;
}

Cat::~Cat() {
	delete _brain;

	std::cout << type << " destroyed" << std::endl;
}

Brain *Cat::getBrain() {
	return _brain;
}

void Cat::makeSound() const {
	std::cout << type << " goes meow-meow 🐈‍⬛" << std::endl;
}
