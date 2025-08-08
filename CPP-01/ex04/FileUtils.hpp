#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <iostream>
#include <fstream>

std::string	readFileContent(const std::string& filename);
void		replaceFileContent(std::string& file_content, const std::string& s1,
				const std::string& s2);
void	writeFileContent(const std::string& filename, const std::string& content);


#endif