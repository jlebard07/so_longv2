/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:00:18 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/20 13:35:24 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_image(t_mlx_data *mlx_data, t_image *image,
						char *path)
{
	image->height = CELL_HEIGHT;
	image->width = CELL_WIDTH;
	image->ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr, \
				path, &(image->width), &(image->height));
	if (image->ptr == NULL)
		display_error(mlx_data, "Error :\n Error loading image\n");
}

void	get_images(t_mlx_data *mlx_data)
{
	init_image(mlx_data, &(mlx_data->floor), "./images/floor.xpm");
	init_image(mlx_data, &(mlx_data->perso), "./images/perso.xpm");
	init_image(mlx_data, &(mlx_data->wall), "./images/wall.xpm");
	init_image(mlx_data, &(mlx_data->object), "./images/object.xpm");
	init_image(mlx_data, &(mlx_data->exit), "./images/exit.xpm");
}
