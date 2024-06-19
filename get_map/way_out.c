/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:09:02 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/19 12:19:04 by jlebard          ###   ########.fr       */
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

static void	explore_positions(bool **verified, char **map,
							t_position *queue, int *new, bool *exit,
							int *count_c, t_position current,
							int **directions)
{
	int			i;
	int			newx;
	int			newy;

	i = 0;
	newx = 0;
	newy = 0;
	while (i < 4)
	{
		newy = current.y + directions[i][0];
		newx = current.x + directions[i][1];
		if (is_way(verified, map, newx, newy))
		{
			verified[newy][newx] = true;
			queue[(*new)++] = (t_position){newx, newy};
			if (map[newy][newx] == 'E')
				*exit = true;
			else if (map[newy][newx] == 'C')
				(*count_c)++;
		}
		i++;
	}
}

static void	progressing(bool **verified, char **map, t_position start,
					int lines, int col, int *count_c, bool *exit)
{
	t_position	*queue;
	t_position	current;
	int			debut;
	int			new;
	int 		i;
	int			**directions;
	
	new = 0;
	debut = 0;
	i = 0;
	queue = (t_position *)malloc(lines * col * sizeof(t_position));
	queue[new++] = start;
	directions = NULL;
	directions = get_directions(directions);
	while (new > debut)
	{
		current = queue[debut++];
		explore_positions(verified, map, queue,\
		&new, exit, count_c, current, directions);
	}
	free(queue);
	i = 0;
	while (i < 4)
		free(directions[i++]);
	free(directions);
}

bool	way_out(t_mlx_data *mlx_data, char **map, int lines, int col)
{
	bool		**verified;
	int			i;
	bool		exit;
	int			count_c;
	t_position	start;
	
	i = 0;
	verified = (bool **)malloc((lines + 1) * sizeof(bool *));
	while (i < lines)
		verified[i++] = (bool *)ft_calloc((size_t)col, sizeof(bool));
	verified[i] = NULL;
	start.x = mlx_data->pos_x;
	start.y = mlx_data->pos_y;
	verified[start.y][start.x] = true;
	exit = false;
	count_c = 0;
	progressing(verified, map, start, lines, col, &count_c, &exit);
	i = 0;
	free_bool_tab(verified);
	return (exit && count_c == check_nbr_collect(mlx_data));
}
