/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:50:06 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/13 18:50:06 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_mlx_data *mlx_data, int x, int y)
{	
	if (mlx_data->map[y - 1][x] != '1')
	{
		if (mlx_data->map[y - 1][x] == 'E')
			is_exit(mlx_data, x, y, 'w');
		else
			empty_or_collect(mlx_data, x, y, 'w');
	}
}

void	move_left(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y][x - 1] != '1')
	{
		if (mlx_data->map[y][x - 1] == 'E')
			is_exit(mlx_data, x, y, 'a');
		else
			empty_or_collect(mlx_data, x, y, 'a');
	}
}

void	move_right(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y][x + 1] != '1')
	{
		if (mlx_data->map[y][x + 1] == 'E')
			is_exit(mlx_data, x, y, 'd');
		else
			empty_or_collect(mlx_data, x, y, 'd');
	}
}

void	move_down(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y + 1][x] != '1')
	{
		if (mlx_data->map[y + 1][x] == 'E')
			is_exit(mlx_data, x, y, 's');
		else
			empty_or_collect(mlx_data, x, y, 's');
	}
}
