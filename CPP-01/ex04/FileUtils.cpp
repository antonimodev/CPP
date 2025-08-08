#include "FileUtils.hpp"

std::string	readFileContent(const std::string& filename) {
	std::ifstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("Error: fail to open " + filename);

	std::string	file_content;
	std::string	line;

	while (std::getline(file, line)) {
		file_content += line;
		if (!file.eof())
			file_content += '\n';
	}
	return file_content;
}

void	replaceFileContent(std::string& file_content, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return;

	size_t init_pos = 0;
	size_t word_pos = file_content.find(s1, init_pos);
	std::string new_content;

	while (word_pos != std::string::npos) {
		new_content.append(file_content.substr(init_pos, word_pos - init_pos));
		new_content.append(s2);
		init_pos = word_pos + s1.length();
		word_pos = file_content.find(s1, init_pos);
	}
	new_content.append(file_content.substr(init_pos));
	file_content = new_content;
}

void	writeFileContent(const std::string& filename, const std::string& content) {
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("Error: fail to create or write in file " + filename);

	file << content;
}
