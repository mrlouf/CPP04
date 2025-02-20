/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:38:41 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 12:30:29 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() {
	std::cout << "Cure constructor" << std::endl;
	type = "cure";
}

Cure::Cure(const Cure &cure) {
	std::cout << "Cure copy constructor" << std::endl;
	*this = cure;
}

Cure::~Cure() {
	std::cout << "Cure destructor" << std::endl;
}

Cure &Cure::operator=(const Cure &cure) {
	std::cout << "Cure assignment operator" << std::endl;
	if (this != &cure) {
		type = cure.type;
	}
	return *this;
}

AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
