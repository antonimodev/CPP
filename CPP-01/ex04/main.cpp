#include "FileUtils.hpp"

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Error: Parameters are <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	const std::string	filename = av[1];
	const std::string	s1 = av[2];
	const std::string s2 = av[3];

	std::string file_content = readFileContent(filename);
	replaceFileContent(file_content, s1, s2);
	writeFileContent("replaced_file", file_content);
	return 0;
}
