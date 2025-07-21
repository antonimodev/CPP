#include <iostream> // Standard input-output std::cout and std::endl
#include <cctype> // std::toupper

void	print_uppercase(char **av) {
	std::string	user_input;
	size_t		i = 0;

	while (*av) {
		user_input = *av++;
		i = 0;
		while (i < user_input.length()) {
			user_input[i] = std::toupper(user_input[i]);
			i++;
		}
		std::cout << user_input;
		if (*av)
			std::cout << " ";
	}
}

int	main(int ac, char *av[]) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return 0;
	}
	av++;
	print_uppercase(av);
	return 0;
}