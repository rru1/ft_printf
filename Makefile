# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user00 <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 22:39:13 by user00            #+#    #+#              #
#    Updated: 2018/03/05 13:18:09 by user00           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $(shell find src -name '*.c')


NAME		=	libftprintf.a
FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(FLAGS)

SRC_PRINTF	=	$(shell find src -name '*.c')
SRC_LIBFT	=	$(shell find libft/src -name '*.c')
SRC			=	$(SRC_LIBFT) $(SRC_PRINTF)

INCLUDES	=	-I includes -I libft/includes
OBJ			=	*.o
OBJDIR		=	./obj/
OBJS		=	$(addprefix $(OBJDIR), $(OBJ))

ifeq ($(OS),Windows_NT)
	RM = del
	RMRF = rd /s /q
	MV = move
	MKDIR = mkdir
else
	RM = rm -f
	RMRF = rm -rf
	MV = mv
	MKDIR = mkdir -p
endif

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC) $(INCLUDES)
		@$(MKDIR) $(OBJDIR)
		@$(MV) $(OBJ) $(OBJDIR)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

#@gcc .main.c $(INCLUDES) $(SRC) libft/libft.a -o rs

clean:
		@$(RM) $(OBJS)
		@$(RMRF) $(OBJDIR)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

main:
	@gcc .main.c $(INCLUDES) $(NAME) -o rs

run:
	@./rs

sure: re run
