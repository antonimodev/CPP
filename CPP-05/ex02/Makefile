# =================== #
#	 VARIABLES	   #
# =================== #

NAME = bureaucratSign
COMPILE = c++
INCLUDES = -IBureaucrat -IAForm -IPresidentialPardonForm -IRobotomyRequestForm -IShrubberyCreationForm
FLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES) -MMD
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))
HEADER = $(OBJ:.o=.d)

# ================== #
#	  SOURCES	   #
# ================== #

SRC =	main.cpp \
		Bureaucrat/Bureaucrat.cpp \
		AForm/AForm.cpp \
		PresidentialPardonForm/PresidentialPardonForm.cpp \
		RobotomyRequestForm/RobotomyRequestForm.cpp \
		ShrubberyCreationForm/ShrubberyCreationForm.cpp \

# ================= #
#	 TARGETS	   #
# ================= #

all: $(NAME)

$(NAME):$(OBJ)
	@$(COMPILE) $(FLAGS) -o $@ $^
	@echo "✅ Successfully compiled!"

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(COMPILE) $(FLAGS) -c $< -o $@

-include $(HEADER)

clean:
	@rm -rf obj/
	@echo "🧹 Successfully cleaned"

fclean: clean
	@rm -f $(NAME)
	@rm -f Undefined_shrubbery

re: fclean all

.PHONY: all clean fclean re