# =================== #
#     VARIABLES       #
# =================== #

NAME = ClapTrap
COMPILE = g++
FLAGS = -Wall -Werror -Wextra -std=c++98
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#      SOURCES       #
# ================== #

SRC =	main.cpp \
		ClapTrap.cpp \

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
	@rm -f $(NAME) 2>/dev/null

re: fclean all

.PHONY: all clean fclean re