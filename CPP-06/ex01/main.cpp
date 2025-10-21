#include "Serializer.hpp"

int	main(void) {
	Data		baseStructure;

	uintptr_t	raw;
	Data*		deserialized;

	raw = Serializer::serialize(&baseStructure);
	deserialized = Serializer::deserialize(raw);

	if (&baseStructure == deserialized)
		std::cout << "Pointers are equal" << std::endl;
	return 0;
}