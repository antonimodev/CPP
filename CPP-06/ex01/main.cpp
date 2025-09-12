#include "Serializer.hpp"

int	main(void) {
	Serializer	serializer;
	Data		baseStructure;

	uintptr_t	raw;
	Data*		deserialized;

	raw = serializer.serialize(&baseStructure);
	deserialized = serializer.deserialize(raw);

	if (&baseStructure == deserialized)
		std::cout << "Pointers are equal" << std::endl;
	return 0;
}