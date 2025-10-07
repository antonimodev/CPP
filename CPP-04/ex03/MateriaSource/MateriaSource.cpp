#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void) : _count(0) {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;

	std::cout << "Materia Source default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _count(other._count) {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
	for (int i = 0; i < 4; i++) {
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}

	std::cout << "Materia Source copy constructor called" << std::endl;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_templates[i]) {
				delete _templates[i];
				_templates[i] = NULL;
			}
		}
		_count = other._count;

		for (int i = 0; i < 4; i++) {
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = NULL;
		}

		std::cout << "Materia Source assignment operator called" << std::endl;
	}
	return *this;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i]) {
			delete _templates[i];
			_templates[i] = NULL;
		}
	}

	std::cout << "Materia Source destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cerr << "Cannot learn a NULL Materia." << std::endl;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (_templates[i] == NULL) {
			_templates[i] = m->clone();
			_count++;
			std::cout << "MateriaSource learned a new Materia of type " << m->getType() << std::endl;
			return;
		}
	}
	std::cerr << "MateriaSource inventory is full, cannot learn more Materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] != NULL) {
			if (_templates[i]->getType() == type) {
				std::cout << "MateriaSource created a new Materia of type " << type << std::endl;
				return _templates[i]->clone();
			}
		}
	}

	std::cout << "MateriaSource could not create Materia of type " << type << std::endl;
	return NULL;
}
