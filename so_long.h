/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:21:08 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/20 15:36:22 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft/libft.h"
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# ifndef CELL_WIDTH
#  define CELL_WIDTH 80
# endif

# ifndef CELL_HEIGHT
#  define CELL_HEIGHT 80
# endif

typedef struct s_way_out
{
	bool	**verified;
	bool	exit;
	int		count_c;
	int		**directions;
	int		new;
	int		col;
	int		lines;
}	t_way_out;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	int		width;
	int		height;
	void	*ptr;
}	t_image;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*window;
	char	**map;
	t_image	wall;
	t_image	floor;
	t_image	object;
	t_image	exit;
	t_image	perso;
	int		pos_x;
	int		pos_y;
	int		count;
}	t_mlx_data;

//vérifications maps
bool	check_chara(char **map);
bool	is_rectangle(char **map);
bool	check_wall(char **map);
bool	way_out(t_mlx_data *mlx_data, char **map, int lines, int col);

//parsing maps and establishing connection
char	**parse_and_check(char *buffer);
void	set_data(t_mlx_data *mlx_data, char *path);

//free and errors
void	free_bool_tab(bool **bool_tab);
int		end_game(t_mlx_data *mlx_data);
void	display_error(t_mlx_data *mlx_data, char *s);
void	free_map(char **map);

//obtention des textures
void	get_images(t_mlx_data *mlx_data);

//gestion de l'affichage
int		affichage(t_mlx_data *mlx_data);

//mouvements du personnage
void	move_up(t_mlx_data *mlx_data, int x, int y);
void	move_right(t_mlx_data *mlx_data, int x, int y);
void	move_down(t_mlx_data *mlx_data, int x, int y);
void	move_left(t_mlx_data *mlx_data, int x, int y);
int		key_press(int keysim, t_mlx_data *mlx_data);
void	get_pos(t_mlx_data *mlx_data);
void	is_exit(t_mlx_data *mlx_data, int x, int y, char direction);
void	empty_or_collect(t_mlx_data *mlx_data, int x, int y, char direction);

int		check_nbr_collect(t_mlx_data *mlx_data);
int		main(int argc, char **argv);

#endif
