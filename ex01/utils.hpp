#ifndef LIB_HPP
#define LIB_HPP

/* INCLUDES */
#include <iostream>
#include <limits>

/* OPTIONS */
# define ADD	1
# define SEARCH	2
# define EXIT	3

/* FUNCTIONS */

/* ----- UTILS ----- */
size_t	get_option(void);
void	display_options(void);
void	error_msg(const std::string error_msg);

#endif