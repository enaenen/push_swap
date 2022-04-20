# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 13:53:37 by wchae             #+#    #+#              #
#    Updated: 2022/04/14 20:03:59 by wchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
AR		= ar rcs
RM		= rm -f
LEAK	= -g3 -fsanitize=address


# ifeq ($(DEBUG),true)
# 		CDEBUG = -g
# endif

# LIBFT
LIBFT_DIR	= ./lib/libft/
LIBFT_FLAGS = -L ./$(LIBFT_DIR) -lft
LIBFT_FILE	= $(LIBFT_DIR)libft.a

SRCS_DIR = ./srcs/
SRC = main.c
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)


all:	$(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:		fclean all

nm :
	norminette $(SRCS)

leak : 
	make -C $(LIBFT_DIR)
	$(CC) $(LEAK) -o $(NAME) $(SRCS) $(LIBFT_FLAGS)
test : make
	./push_swap 4 5 1 3 8


.PHONY: all re bonus clean fclean