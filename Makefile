# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#              #
#    Updated: 2023/05/10 12:23:25 by aotsala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
LIB = libft/libft.a

SRC = push_swap.c parse.c parse_extra.c helper.c lst_find.c actions.c \
		runner.c rotation.c calc.c do.c cases.c
		
SRC_B = s_checker_bonus.c s_parse_bonus.c s_parse_extra_bonus.c \
		s_runner_bonus.c s_actions_bonus.c

CC = cc
CFLAGS = -Wall -Werror -Wextra

COMP = $(CC) $(CFLAGS) $(LIB)

RM = rm -f

all:	$(NAME) $(BONUS)

$(NAME):	$(OBJ)
						$(MAKE) bonus -C ./libft
						$(COMP) $(OBJ) -o $(NAME)
bonus: $(BONUS)

$(BONUS):	$(OBJ_B)
						$(MAKE) bonus -C ./libft
						$(COMP) $(OBJ_B) -o $(BONUS)

clean:
		$(RM) $(OBJ)
		$(RM) $(OBJ_B)
		$(MAKE) clean -C ./libft
		
fclean:	clean
		$(RM) $(NAME)
		$(RM) $(BONUS)
		$(MAKE) fclean -C ./libft

re:		fclean all