# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchae <wchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 11:28:46 by wchae             #+#    #+#              #
#    Updated: 2022/05/01 16:58:54 by wchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
RM = rm -rf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_strlcpy.c ft_strndup.c ft_split.c ft_isdigit.c ft_isspace.c ft_atoi.c ft_memset.c ft_calloc.c ft_strcmp.c
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: clean fclean re all