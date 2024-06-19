# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 12:15:54 by jlebard           #+#    #+#              #
#    Updated: 2024/06/15 10:47:15 by jlebard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c ft_printf.c \
printf_src/printf_decimal.c printf_src/printf_hexa.c printf_src/printf_hexa2.c \
printf_src/printf_ptr.c printf_src/printf_str.c printf_src/printf_unsigned.c
OBJ = $(SRC:%.c=%.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
AR = ar rcs
CLEAN = rm -rf 
FCLEAN = rm -f 

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(CLEAN) $(OBJ)

fclean:	clean
	$(FCLEAN) $(NAME)

re:	fclean all
