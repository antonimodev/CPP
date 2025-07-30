#ifndef LIB_HPP
#define LIB_HPP

/* INCLUDES */
#include <iostream>
#include <limits>
#include <iomanip>

/* OPTIONS */
# define ADD	1
# define SEARCH	2
# define EXIT	3

/* FUNCTIONS */

/* ----- UTILS ----- */
size_t		get_option(void);
void		display_options(void);
std::string	get_user_input(std::string msg);
void		error_msg(const std::string error_msg);
std::string	formatField(const std::string& str);

#endif