/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:39:22 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/19 16:39:24 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria() {
	std::cout << "Default AMateria constructed" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	*this = other;
}

AMateria &AMateria::operator=(AMateria const &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria destroyed" << std::endl;
}

AMateria::AMateria(std::string const &type) {
	this->type = type;
}

std::string const &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "AMateria used" << std::endl;
}
