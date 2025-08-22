#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	_templates[4];
		int			_count;

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		virtual ~MateriaSource(void);

		void		learnMateria(AMateria* m) override;
		AMateria*	createMateria(std::string const& type) override;
};

#endif
