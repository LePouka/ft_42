# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtissera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:11:03 by rtissera          #+#    #+#              #
#    Updated: 2022/11/28 14:13:05 by rtissera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_memcmp.c ft_memmove.c ft_putchar_fd.c ft_putnbr_fd.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strmapi.c ft_strnstr.c ft_strtrim.c ft_tolower.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_strchr.c ft_striteri.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_substr.c ft_toupper.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = ft_lstadd_back.c  ft_lstadd_front.c  ft_lstclear.c  ft_lstdelone.c  ft_lstiter.c  ft_lstlast.c  ft_lstmap.c  ft_lstnew.c  ft_lstsize.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus : $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

tildeclean :
	rm -rf *~ .*~

re : fclean all

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

.PHONY : all bonus clean fclean tildeclean re
