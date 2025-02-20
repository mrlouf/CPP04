/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:31:00 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 14:27:49 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	*this = materiaSource;
}

MateriaSource::~MateriaSource() {
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
	if (this != &materiaSource)	{
		for (int i = 0; i < 4; i++) {
			this->materia[i] = materiaSource.materia[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	(void)m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	if (type == "cure")
		return new Cure();
	else if (type == "ice")
		return new Ice();
	return NULL;
}
