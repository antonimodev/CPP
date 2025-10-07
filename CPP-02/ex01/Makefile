# =================== #
#	 VARIABLES	   #
# =================== #

NAME = fixed
COMPILE = g++
INCLUDES = -IFixed
FLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES)
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#	  SOURCES	   #
# ================== #

SRC =	main.cpp \
		Fixed/Fixed.cpp \

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