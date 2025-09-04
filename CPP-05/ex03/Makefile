# =================== #
#     VARIABLES       #
# =================== #

NAME = bureaucratSign
COMPILE = c++
INCLUDES = -IBureaucrat -IAForm -IPresidentialPardonForm -IRobotomyRequestForm -IShrubberyCreationForm -IIntern
FLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES)
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#      SOURCES       #
# ================== #

SRC =	main.cpp \
		Bureaucrat/Bureaucrat.cpp \
		AForm/AForm.cpp \
		PresidentialPardonForm/PresidentialPardonForm.cpp \
		RobotomyRequestForm/RobotomyRequestForm.cpp \
		ShrubberyCreationForm/ShrubberyCreationForm.cpp \
		Intern/Intern.hpp \

# ================= #
#     TARGETS       #
# ================= #

all: $(NAME)

$(NAME):$(OBJ)
	@$(COMPILE) $(FLAGS) -o $@ $^
	@echo "✅ Successfully compiled!"

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	@rm -rf obj/
	@echo "🧹 Successfully cleaned"

fclean: clean
	@rm -f $(NAME)
	@rm -f Undefined_shrubbery

re: fclean all

.PHONY: all clean fclean re