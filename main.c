/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:40 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/19 14:35:37 by jlebard          ###   ########.fr       */
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
	free_image(mlx_data->mlx_ptr, mlx_data->exit.ptr);
	free_image(mlx_data->mlx_ptr, mlx_data->floor.ptr);
	free_image(mlx_data->mlx_ptr, mlx_data->object.ptr);
	free_image(mlx_data->mlx_ptr, mlx_data->perso.ptr);
	free_image(mlx_data->mlx_ptr, mlx_data->wall.ptr);
	free_cnctn(mlx_data, 1, 1, 0);
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
		ft_putstr_fd("Enter 1 .ber arg", 2);
		return (1);
	}
	mlx_data.window = NULL;
    mlx_data.map = NULL;
    mlx_data.floor.ptr = NULL;
    mlx_data.perso.ptr = NULL;
    mlx_data.wall.ptr = NULL;
    mlx_data.object.ptr = NULL;
    mlx_data.exit.ptr = NULL;
	set_data(&mlx_data, ft_strjoin("./maps/", argv[1]));
	mlx_loop_hook(mlx_data.mlx_ptr, &affichage, &mlx_data);
	mlx_hook(mlx_data.window, KeyRelease, 0, &key_press, &mlx_data);
	mlx_hook(mlx_data.window, DestroyNotify, 0, \
			&end_game, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
	end_game(&mlx_data);
	return (0);	
}
