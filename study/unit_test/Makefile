# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 21:22:26 by wchae             #+#    #+#              #
#    Updated: 2022/04/27 22:23:44 by wchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= push_swap

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
RM		= rm -f
LEAK	= -g3 -fsanitize=address

LIBFT_DIR	= ./libft/
LIBFT_FLAGS = -L ./$(LIBFT_DIR) -lft
LIBFT_FILE	= $(LIBFT_DIR)libft.a

SRC = main.c parse.c stack.c #pushs.c reverse_rotates.c swaps.c rotates.c
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

# leak : 
# 	make -C $(LIBFT_DIR)
# 	$(CC) $(LEAK) -o $(NAME) $(SRCS) $(LIBFT_FLAGS)
