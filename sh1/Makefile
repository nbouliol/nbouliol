# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/19 12:16:09 by nbouliol          #+#    #+#              #
#    Updated: 2015/03/24 17:40:06 by nbouliol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C          = gcc

NAME       = ft_minishell1

SRC_C         = path.c\
				cd.c\
				env.c\
				prompt.c\
				check.c\
				tools.c\
				main.c\
		
SRC_H 		= libft/libft.h\

LIBA		= libft/libft.a\

OBJ         = $(SRC_C:.c=.o)

LIBFT		= libft/

CFLAGS      = -Wall -Werror -Wextra

RM          = rm -rf

all:        $(NAME)

$(NAME):   $(OBJ)
	@make -C $(LIBFT)
#	@$(CC) -c $(SRC_C) 
	@$(C) $(CFLAGS) $(OBJ) -I $(SRC_H) $(LIBA) -o $(NAME)

	@echo "\033[0;31m$(NAME) \033[1;33mhas been created\033[0m"


clean:
	@$(RM) $(OBJ)
	@echo "\033[0;32mall \033[0;31m.o \033[0;32mhave been deleted"

fclean:     clean
	@$(RM) $(NAME)
	@echo "\033[0;32mit's all clean, \033[0;31m$(NAME) \033[0;32mhas been deleted too"

re:         fclean all
	@echo "\033[1;34meverything's OK ! \033[0;31m:)\033[0m"

%.o:        %.c
	@$(C)  -c $< -o $@

.PHONY:     all clean re fclean
