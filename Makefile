# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 13:53:37 by wchae             #+#    #+#              #
#    Updated: 2022/04/14 16:48:30 by wchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
RM		= rm -f
LEAK	= -g3 -fsanitize=address


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

.PHONY: all re bonus clean fclean