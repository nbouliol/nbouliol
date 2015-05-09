# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouliol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/05 19:34:21 by nbouliol          #+#    #+#              #
#    Updated: 2015/05/05 19:34:22 by nbouliol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC            =     main.c\
					 hook.c\
					 img.c\
					 julia.c\
					 tricorn.c\
					 mandelbort.c\
					 vicky.c\
					 four.c\
					 key_hook.c\

NAME        =     fractol
CC            =     gcc
CFLAGS        =     -Werror -Wextra -Wall -O3
OBJ            =     $(SRC:.c=.o)
RM            =     rm -rf
INCLUDES    =    libft
OBJ         =    $(SRC:.c=.o)
LIBFT        =    libft
HEADERS        =    -I ./libft -I ./mlx
LIB            =    libft.a
LIBS        =    ./libft/libft.a ./mlx/libmlx.a
LIBS        +=    -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./mlx
	@echo "compiling [\033[1;33mMLX\033[0m]"
	@make -C $(LIBFT)
	@echo "compiling [\033[1;32mLIBFT\033[0m]"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@echo "compiling [\033[1;34m$(NAME)\033[0m]"

.c.o:
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@

clean:
	@$(RM) $(OBJ)
	@echo "removing *\033[1;31m.o\033[0m"
	@make clean -C mlx
	@echo "cleaning [\033[1;31mMLX\033[0m]"
	@make clean -C libft
	@echo "cleaning [\033[1;31mLIBFT\033[0m]"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

re:    fclean all

help:
	@echo "fleches pour bouger"
	@echo "+ / -  | molette pour zoomer"
	@echo "X / C pour activer / desactiver la souris dans julia"
	@echo "A / D pour changer la fractale julia"
	@echo "clic gauche / droit pour augmenter / diminuer le nombre d'iterations"
	@echo "S pour switcher d'une fractale a l'autre"

.PHONY: all clean fclean re
