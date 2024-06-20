/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:40 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/20 14:09:45 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_conform(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	if (i < 4)
		return (0);
	if (ft_strncmp(arg + i - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	end_game(t_mlx_data *mlx_data)
{
	free_map(mlx_data->map);
	if (mlx_data->mlx_ptr != NULL)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->wall.ptr);
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->object.ptr);
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->perso.ptr);
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->floor.ptr);
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->exit.ptr);
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->window);
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
	}
	exit (1);
	return (0);
}

void	get_pos(t_mlx_data *mlx_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx_data->map[i])
	{
		while (mlx_data->map[i][j])
		{
			if (mlx_data->map[i][j] == 'P')
			{
				mlx_data->pos_x = j;
				mlx_data->pos_y = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_nbr_collect(t_mlx_data *mlx_data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (mlx_data->map[i])
	{
		while (mlx_data->map[i][j])
		{
			if (mlx_data->map[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlx_data;

	if (argc != 2 || is_conform(argv[1]) != 1)
	{
		ft_putstr_fd("Error :\nEnter 1 .ber arg\n", 2);
		return (1);
	}
	mlx_data.count = 0;
	mlx_data.mlx_ptr = NULL;
	set_data(&mlx_data, argv[1]);
	mlx_loop_hook(mlx_data.mlx_ptr, &affichage, &mlx_data);
	mlx_hook(mlx_data.window, KeyRelease, KeyReleaseMask,
		&key_press, &mlx_data);
	mlx_hook(mlx_data.window, DestroyNotify, 0,
		&end_game, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
	end_game(&mlx_data);
	return (0);
}	
