# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                                :+:    :+:        #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 20:11:18 by nmartins       #+#    #+#                 #
#    Updated: 2019/04/29 19:37:49 by nmartins            ########   odam.nl    #
#                                                                              #
# **************************************************************************** #

#############
# variables #
#############

# configure
NAME=fdf

MAIN=			fdf
OBJECT_NAMES=	

# do not configure
CC=gcc
INCLUDES=-I./inc -I./libft -I./$(MINILIB)
TEST_INCLUDS=-I$(HOME)/.brew/include
SRC=./src
OBJ=./.obj
LIBFT=./libft
MINILIB=./minilibx_macos
EXTRA=
CFLAGS=-Werror -Wall -Wextra $(EXTRA)
LFLAGS=-L$(LIBFT) -lft -L$(MINILIB) -lmlx
OBJECTS=$(patsubst %, $(OBJ)/%.o, $(MAIN) $(OBJECT_NAMES))
SOURCES=$(patsubst %, $(SRC)/%.c, $(MAIN) $(OBJECT_NAMES))

# colors feel free to add more as you need them
OK_COLOR=\x1b[32;01m
RESET=\x1b[0m
UNDERLINE=\x1b[4m
BLUE=\x1b[36m
RED=\x1b[31m

#########
# rules #
#########
all: $(NAME)

test: $(TEST_NAME)
	@./$(TEST_NAME)

debug:
	$(MAKE) -B "EXTRA=$(EXTRA) -g"

$(LIBFT)/libft.a:
	@echo ">>= Making libft"
	@$(MAKE) -C $(LIBFT)
	@echo ">>= Done making libft"

libft_clean:
	@$(MAKE) -C $(LIBFT) clean

libft_fclean:
	@$(MAKE) -C $(LIBFT) fclean

$(MINILIB)/libmlx.a:
	@echo ">>= Making minilibx"
	@$(MAKE) -C $(MINILIB)
	@echo ">>= Done making minilibx"

minilib_clean:
	@$(MAKE) -C $(MINILIB) clean

$(NAME): $(LIBFT)/libft.a $(MINILIB)/libmlx.a $(OBJECTS)
	@printf " λ Linking $(UNDERLINE)$(BLUE)$@$(RESET)\n"
	@$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LFLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	@printf " λ Making object $(UNDERLINE)$(BLUE)$^$(RESET)\n"
	@$(CC) -c -o $@ $^ $(CFLAGS) $(INCLUDES)

clean: minilib_clean libft_clean
	@echo "$(RED)Cleaning objects$(RESET)"
	@rm -rf $(OBJ)

fclean: libft_fclean clean
	@echo "$(RED)Cleaning $(NAME) and $(TEST_NAME)$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(TEST_NAME)

re: fclean all

.SECONDARY: $(OBJECTS)
.PHONY: all debug libft clean fclean re
