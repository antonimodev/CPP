# =================== #
#	 VARIABLES	   #
# =================== #

NAME = fileReplace
COMPILE = g++
INCLUDES = -IFileUtils
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDES)
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

# ================== #
#	  SOURCES	   #
# ================== #

SRC =	main.cpp \
		FileUtils/FileUtils.cpp \

# ================= #
#	 TARGETS	   #
# ================= #

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMPILE) $(FLAGS) -o $@ $^
	@echo "✅ Successfully compiled!"

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	@rm -rf obj/
	@echo "🧹 Successfully cleaned"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re