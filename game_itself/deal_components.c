/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_components.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:08:45 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/19 14:00:06 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	empty_or_collect(t_mlx_data *mlx_data, int x, int y, char direction)
{
	mlx_data->map[y][x] = '0';
	if (direction == 'w')
		mlx_data->map[y - 1][x] = 'P';
	else if (direction == 's')
		mlx_data->map[y + 1][x] = 'P';
	else if (direction == 'd')
		mlx_data->map[y][x + 1] = 'P';
	else if (direction == 'a')
		mlx_data->map[y][x - 1] = 'P'; 
	get_pos(mlx_data);
	mlx_data->count++;
	ft_printf("Nombre de mouvements : %d", mlx_data->count);
}

void	is_exit(t_mlx_data *mlx_data, int x, int y, char direction)
{
	mlx_data->map[y][x] = '0';
	if (check_nbr_collect(mlx_data) == 0)
	{
		mlx_data->map[y][x] = '0';
		if (direction == 'w')
			mlx_data->map[y - 1][x] = 'P';
		else if (direction == 's')
			mlx_data->map[y + 1][x] = 'P';
		else if (direction == 'd')
			mlx_data->map[y][x + 1] = 'P';
		else if (direction == 'a')
			mlx_data->map[y][x - 1] = 'P'; 
		get_pos(mlx_data);
		mlx_data->count++;
		ft_printf("Vous avez fini la map en %d mouvements", mlx_data->count);
		end_game(mlx_data);
	}
}
		
