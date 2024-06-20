/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:15:39 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/19 18:07:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	nb_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	nb_col(char	*first_line)
{
	int	i;
	
	i = 0;
	while (first_line[i])
		i++;
	return (i);
}

void	display_error(t_mlx_data *mlx_data, char *s)
{
	if (s != "" && s!= NULL)
		ft_putstr_fd(s, 2);
	end_game(mlx_data);
}

void	set_data(t_mlx_data *mlx_data, char *path)
{
	int	x_lines;
	int	y_col;
	
	mlx_data->mlx_ptr = mlx_init();
	if (mlx_data->mlx_ptr == NULL)
		display_error(mlx_data, \
		"Impossible d'établir la connection\n");
	mlx_data->map = parse_and_check(path);
	if (mlx_data->map == NULL)
		display_error(mlx_data, \
		"Mauvais format de carte\n");
	x_lines = nb_lines(mlx_data->map);
	y_col	= nb_col(mlx_data->map[0]);
	get_pos(mlx_data);
	if (way_out(mlx_data, mlx_data->map, x_lines, y_col)\
		== false)
		display_error(mlx_data, "Il faut un chemin\n")
	get_images(mlx_data);
	mlx_data->window = mlx_new_window(mlx_data->mlx_ptr, \
	y_col * CELL_WIDTH, x_lines * CELL_HEIGHT, "window");
	if (mlx_data->window == NULL)
		display_errror(mlx_data, "Erreur dans l'ouverture \
			de la fenêtre");
}
