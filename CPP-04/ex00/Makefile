# =================== #
#	 VARIABLES	   #
# =================== #

NAME = polymorphism
COMPILE = c++
INCLUDES = -IAnimal -ICat -IDog -IWrongAnimal -IWrongCat
FLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES) -MMD
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))
HEADER = $(OBJ:.o=.d)

# ================== #
#	  SOURCES	   #
# ================== #

SRC =	main.cpp \
		Animal/Animal.cpp \
		Dog/Dog.cpp \
		Cat/Cat.cpp \
		WrongAnimal/WrongAnimal.cpp \
		WrongCat/WrongCat.cpp \

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

re: fclean all

.PHONY: all clean fclean re