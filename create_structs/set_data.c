/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:15:39 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/19 14:34:15 by jlebard          ###   ########.fr       */
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

void	free_cnctn(t_mlx_data *mlx_data, bool map,
					bool window, bool end)
{
	if (window)
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->window);
	if (map)
		free_tab(mlx_data->map);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
	free (mlx_data);
	if (end)
	{
		perror(
			"Error establishing connection / opening the window"
			);
		exit (1);
	}
}

void	set_data(t_mlx_data *mlx_data, char *path)
{
	int	x_lines;
	int	y_col;
	
	mlx_data->map = parse_and_check(path);
	if (mlx_data->map == NULL)
		exit (1);
	x_lines = nb_lines(mlx_data->map);
	y_col	= nb_col(mlx_data->map[0]);
	get_pos(mlx_data);
	if (way_out(mlx_data, mlx_data->map, x_lines, y_col)\
			== 0)
	{
		map_error(mlx_data->map);
		exit (1);	
	}	
	mlx_data->mlx_ptr = mlx_init();
	if (mlx_data->mlx_ptr == NULL)
		free_cnctn(mlx_data, 1, 0, 1);
	get_images(mlx_data);
	mlx_data->window = mlx_new_window(
		mlx_data->mlx_ptr,
		y_col * CELL_WIDTH,
		x_lines * CELL_HEIGHT,
		"window"
		);
	if (mlx_data->window == NULL)
		free_cnctn(mlx_data, 1, 1, 1);
}
