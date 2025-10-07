# =================== #
#	 VARIABLES	   #
# =================== #

NAME = polymorphism
COMPILE = g++
INCLUDES = -IAnimal -ICat -IDog -IWrongAnimal -IWrongCat -IBrain
FLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES)
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#	  SOURCES	   #
# ================== #

SRC =	main.cpp \
		Animal/Animal.cpp \
		Dog/Dog.cpp \
		Cat/Cat.cpp \
		WrongAnimal/WrongAnimal.cpp \
		WrongCat/WrongCat.cpp \
		Brain/Brain.cpp \

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

clean:
	@rm -rf obj/
	@echo "🧹 Successfully cleaned"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re