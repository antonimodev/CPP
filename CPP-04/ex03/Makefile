# =================== #
#     VARIABLES       #
# =================== #

NAME = materia
COMPILE = c++
INCLUDES = -IAMateria -ICharacter -ICure -IIce -IMateriaSource
FLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES)
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#      SOURCES       #
# ================== #

SRC =	main.cpp \
		Ice/Ice.cpp \
		Cure/Cure.cpp \
		Character/Character.cpp \
		MateriaSource/MateriaSource.cpp \
		AMateria/AMateria.cpp

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

re: fclean all

.PHONY: all clean fclean re