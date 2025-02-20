/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:50:21 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 12:50:23 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character() {
	std::cout << "Character constructor" << std::endl;
	_name = "Anonymous";
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	std::cout << "Character constructor" << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &character) {
	std::cout << "Character copy constructor" << std::endl;
	*this = character;
}

Character::~Character() {
	std::cout << "Character destructor" << std::endl;
}

Character &Character::operator=(const Character &character) {
	std::cout << "Character assignment operator" << std::endl;
	if (this != &character) {
		_name = character._name;
		// TODO: deep copy of inventory too
	}
	return *this;
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	(void)m;
	// TODO: implement equip
}

void Character::unequip(int idx) {
	(void)idx;
	// TODO: implement unequip
}

void Character::use(int idx, ICharacter &target) {
	(void)idx;
	(void)target;
	// TODO: implement use
}
