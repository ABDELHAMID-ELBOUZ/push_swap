# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 16:37:57 by aelbouz           #+#    #+#              #
#    Updated: 2025/03/21 20:03:47 by aelbouz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc 

FLAGS = -Wall -Wextra -Werror -g -g -fsanitize=address,undefined

RM = rm -f

SRCS = Mandatory/main.c Mandatory/ft_format.c Mandatory/ft_puthexa.c  Mandatory/ft_putptr.c   Mandatory/ft_putunint.c \
Mandatory/ft_printf.c   Mandatory/ft_putchar.c  Mandatory/ft_putnbr.c   Mandatory/ft_putstr.c Mandatory/ft_strchr.c \
Mandatory/parser.c Mandatory/ft_atoi.c Mandatory/ft_strlen.c Mandatory/parser_help.c Mandatory/ft_strdup.c \
Mandatory/ft_strtrim.c Mandatory/ft_strlcpy.c Mandatory/ft_strlcat.c Mandatory/ft_strjoin.c Mandatory/ft_lstadd_back.c \
Mandatory/ft_lstclear.c Mandatory/ft_lstnew.c Mandatory/ft_lstnew.c Mandatory/ft_split.c Mandatory/ft_substr.c \
Mandatory/operations1.c Mandatory/operations2.c Mandatory/operations3.c Mandatory/operations4.c Mandatory/sort_utils.c \
Mandatory/sort.c Mandatory/ft_lstsize.c Mandatory/chunk_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@
clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
