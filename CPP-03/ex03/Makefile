# =================== #
#     VARIABLES       #
# =================== #

NAME = diamondtrap
COMPILE = c++
INCLUDES = -IClapTrap -IScavTrap -IFragTrap -IDiamondTrap
FLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES)
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#      SOURCES       #
# ================== #

SRC =	main.cpp \
		ClapTrap/ClapTrap.cpp \
		ScavTrap/ScavTrap.cpp \
		FragTrap/FragTrap.cpp \
		DiamondTrap/DiamondTrap.cpp

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