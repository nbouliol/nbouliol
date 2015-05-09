# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouliol <nbouliol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/19 12:16:09 by nbouliol          #+#    #+#              #
#    Updated: 2015/04/07 16:18:46 by nbouliol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C          = gcc

NAME       = libft.a

SRC_C         = ft_atoi.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_swap.c \
				ft_epur_str.c\
				get_next_line.c\
				ft_free_tab.c\

SRC_H 		= libft.h

OBJ         = $(SRC_C:.c=.o)

CFLAGS      = -Wall -Werror -Wextra

RM          = rm -rf

all:        $(NAME)

$(NAME):    
	@$(CC) $(CFLAGS) -c $(SRC_C)
	@ar rc $(NAME) $(OBJ) $(SRC_H)
	@ranlib $(NAME)
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
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:     all clean re fclean
