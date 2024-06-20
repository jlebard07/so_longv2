/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:09:02 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/20 15:38:34 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	is_way(bool **verified, char **map, int x, int y)
{
	return (!verified[y][x] && map[y][x] != '1');
}

static int	**get_directions(int **directions)
{
	int	i;

	i = 0;
	directions = (int **)malloc(4 * sizeof(int *));
	while (i < 4)
	{
		directions[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}
	directions[0][0] = 1;
	directions[0][1] = 0;
	directions[1][0] = 0;
	directions[1][1] = 1;
	directions[2][0] = -1;
	directions[2][1] = 0;
	directions[3][0] = 0;
	directions[3][1] = -1;
	return (directions);
}

static void	explore_positions(t_way_out *datas, char **map,
							t_position *queue, t_position current)
{
	int			i;
	int			newx;
	int			newy;

	i = 0;
	newx = 0;
	newy = 0;
	while (i < 4)
	{
		newy = current.y + datas->directions[i][0];
		newx = current.x + datas->directions[i][1];
		if (is_way(datas->verified, map, newx, newy))
		{
			datas->verified[newy][newx] = true;
			queue[datas->new++] = (t_position){newx, newy};
			if (map[newy][newx] == 'E')
				datas->exit = true;
			else if (map[newy][newx] == 'C')
				datas->count_c++;
		}
		i++;
	}
}

static void	progressing(char **map, t_position start, t_way_out *datas)
{
	t_position	*queue;
	t_position	current;
	int			debut;
	int			i;

	datas->new = 0;
	debut = 0;
	i = 0;
	queue = (t_position *)malloc(datas->lines * datas->col * sizeof(t_position));
	queue[datas->new++] = start;
	while (datas->new > debut)
	{
		current = queue[debut++];
		explore_positions(datas, map, queue, current);
	}
	free(queue);
	i = 0;
	while (i < 4)
		free(datas->directions[i++]);
	free(datas->directions);
}

bool	way_out(t_mlx_data *mlx_data, char **map, int lines, int col)
{
	t_way_out	datas;
	int			i;
	t_position	start;

	i = 0;
	datas.verified = (bool **)malloc((lines + 1) * sizeof(bool *));
	while (i < lines)
		datas.verified[i++] = (bool *)ft_calloc((size_t)col, sizeof(bool));
	datas.verified[i] = NULL;
	start.x = mlx_data->pos_x;
	start.y = mlx_data->pos_y;
	datas.verified[start.y][start.x] = true;
	datas.exit = false;
	datas.count_c = 0;
	datas.col = col;
	datas.lines = lines;
	datas.directions = NULL;
	datas.directions = get_directions(datas.directions);
	progressing(map, start, &datas);
	i = 0;
	free_bool_tab(datas.verified);
	return (datas.exit && datas.count_c == check_nbr_collect(mlx_data));
}
