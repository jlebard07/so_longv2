/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:22:31 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/13 17:22:31 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	display_image(t_mlx_data *mlx_data, t_image *img,
							int x, int y)
{
	mlx_put_image_to_window(mlx_data->mlx_ptr,
		mlx_data->window, img->ptr, x * img->width,
		y * img->height);
}

static void	display_components(t_mlx_data *mlx_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx_data->map[i])
	{
		while (mlx_data->map[i][j])
		{
			if (mlx_data->map[i][j] == '1')
				display_image(mlx_data, &(mlx_data->wall), j, i);
			else if (mlx_data->map[i][j] == '0')
				display_image(mlx_data, &(mlx_data->floor), j, i);
			else if (mlx_data->map[i][j] == 'C')
				display_image(mlx_data, &(mlx_data->object), j, i);
			else if (mlx_data->map[i][j] == 'E')
				display_image(mlx_data, &(mlx_data->exit), j, i);
			else if (mlx_data->map[i][j] == 'P')
				display_image(mlx_data, &(mlx_data->perso), j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

int	key_press(int keysim, t_mlx_data *mlx_data)
{
	if (keysim == XK_Escape)
		end_game(mlx_data);
	if (keysim == XK_w)
		move_up(mlx_data, mlx_data->pos_x, mlx_data->pos_y);
	if (keysim == XK_a)
		move_left(mlx_data, mlx_data->pos_x, mlx_data->pos_y);
	if (keysim == XK_d)
		move_right(mlx_data, mlx_data->pos_x, mlx_data->pos_y);
	if (keysim == XK_s)
		move_down(mlx_data, mlx_data->pos_x, mlx_data->pos_y);
	return (0);
}

int	affichage(t_mlx_data *mlx_data)
{
	display_components(mlx_data);
	return (0);
}
