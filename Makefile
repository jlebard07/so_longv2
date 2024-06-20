# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 14:27:37 by jlebard           #+#    #+#              #
#    Updated: 2024/06/10 14:27:37 by jlebard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c ./create_structs/set_data.c ./create_structs/set_images.c \
./game_itself/deal_components.c ./game_itself/display_img.c ./game_itself/moves.c \
./get_map/check_map.c ./get_map/get_map.c ./get_map/way_out.c
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lX11 -lXext
OBJ = $(SRC:%.c=%.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): libft mlx $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft.a libmlx.a $(MLXFLAGS) -o $(NAME)

mlx:
	$(MAKE) -sC ./minilibx-linux/
	cp ./minilibx-linux/libmlx.a .

libft:
	$(MAKE) -sC ./libft/
	cp libft/libft.a .

clean:
	rm -f $(OBJ)
	rm -f *.a
	$(MAKE) clean -sC ./minilibx-linux/
	rm -f libft/libft.a
	$(MAKE) clean -sC ./libft/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft mlx
