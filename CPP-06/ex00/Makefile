# =================== #
#	 VARIABLES	   #
# =================== #

NAME = scalarconverter
COMPILE = c++
INCLUDES = -IScalarConverter
FLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES) -MMD
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))
HEADER = $(OBJ:.o=.d)

# ================== #
#	  SOURCES	   #
# ================== #

SRC =	main.cpp \
		ScalarConverter/ScalarConverter.cpp \

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