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

AMateria::AMateria(const AMateria& other) {}

AMateria &AMateria::operator=(AMateria const &other) {}

AMateria::~AMateria() {
	std::cout << "AMateria destroyed" << std::endl;
}

AMateria::AMateria(std::string const &type) {}

std::string const &AMateria::getType() const {}

AMateria* AMateria::clone() const {}

void AMateria::use(ICharacter& target) {}
