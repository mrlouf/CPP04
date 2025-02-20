/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:50:21 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 14:14:20 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"

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
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
		}
	}
}

Character &Character::operator=(const Character &character) {
	std::cout << "Character assignment operator" << std::endl;
	if (this != &character) {
		_name = character._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];	// delete old inventory
		}
		for (int i = 0; i < 4; i++) {
			_inventory[i] = character._inventory[i];	// copy inventory from other character
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	(void)idx;
	// TODO: implement unequip
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
		_inventory[idx]->use(target);
	}
}
