/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:00:18 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/19 14:24:10 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_image(t_mlx_data *mlx_data, void *img_ptr)
{
	if (img_ptr != NULL)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, img_ptr);
		img_ptr = NULL;
	}
}

static void	init_image(t_mlx_data *mlx_data, t_image *image,
						char *path)
{
	image->height = CELL_HEIGHT;
	image->width = CELL_WIDTH;
	image->ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr, \
				path, &(image->width), &(image->height));
	if (image->ptr == NULL)
	{
		free_cnctn(mlx_data, 1, 1, 0);
		free_image(mlx_data, mlx_data->exit.ptr);
		free_image(mlx_data, mlx_data->floor.ptr);
		free_image(mlx_data, mlx_data->object.ptr);
		free_image(mlx_data, mlx_data->perso.ptr);
		free_image(mlx_data, mlx_data->wall.ptr);
		perror("Failed loading image");
		exit(1);
	}
}

void	get_images(t_mlx_data *mlx_data)
{
	init_image(mlx_data, &(mlx_data->floor), "./images/floor.xpm");
	init_image(mlx_data, &(mlx_data->perso), "./images/perso.xpm");
	init_image(mlx_data, &(mlx_data->wall), "./images/wall.xpm");
	init_image(mlx_data, &(mlx_data->object), "./images/object.xpm");
	init_image(mlx_data, &(mlx_data->exit), "./images/exit.xpm");
}
