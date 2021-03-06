# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user00 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 13:26:38 by user00            #+#    #+#              #
#    Updated: 2018/01/17 13:26:41 by user00           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = *.o
LIB = libft
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ar rcs $(NAME) $(LIB)/$(OBJ)

$(OBJ):
	@make re -C $(LIB) 
	@$(CC) $(CFLAGD) -c -I header/ source/$(SRC)

clean:
	@rm -f $(OBJ)
	@rm -f libft/$(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all
