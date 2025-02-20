/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:38:44 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 12:30:42 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() {
	std::cout << "Ice constructor" << std::endl;
	type = "ice";
}

Ice::Ice(const Ice &ice) {
	std::cout << "Ice copy constructor" << std::endl;
	*this = ice;
}

Ice::~Ice() {
	std::cout << "Ice destructor" << std::endl;
}

Ice &Ice::operator=(const Ice &ice) {
	std::cout << "Ice assignation operator" << std::endl;
	if(this != &ice)
		type = ice.type;
	return *this;
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
