#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_ISlots[i] = NULL;
	std::cout << "Character " << _name << " has been created." << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		_ISlots[i] = NULL;
	}

	for (int i = 0; i < 4; i++) {
		if (other._ISlots[i])
			_ISlots[i] = other._ISlots[i]->clone();
		else
			_ISlots[i] = NULL;
	}
	std::cout << "Character " << _name << " has been copied." << std::endl;
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_ISlots[i]) {
				delete _ISlots[i];
				_ISlots[i] = NULL;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (other._ISlots[i])
				_ISlots[i] = other._ISlots[i]->clone();
			else
				_ISlots[i] = NULL;
		}
		std::cout << "Character " << _name << " has been assigned." << std::endl;
	}
	return *this;
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++) {
		if (_ISlots[i]) {
			delete _ISlots[i];
			_ISlots[i] = NULL;
		}
	}
	std::cout << "Character " << _name << " has been deleted." << std::endl;
}

std::string const&	Character::getName(void) const {
	return _name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_ISlots[i] == NULL) {
			_ISlots[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		return;
	_ISlots[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4)
		return;
	if (_ISlots[idx] == NULL)
		return;

	_ISlots[idx]->use(target);
}