/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:50:21 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 15:02:11 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"

Character::Character() {
	_name = "Anonymous";
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	_name = name;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &character) {
	*this = character;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
		}
	}
}

Character &Character::operator=(const Character &character) {
	if (this != &character) {
		_name = character._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];	// Delete old inventory
		}
		for (int i = 0; i < 4; i++) {
			_inventory[i] = character._inventory[i]->clone();	// Copy inventory from other character
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
			return;
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
