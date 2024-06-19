/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:18:33 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/19 10:48:12 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

bool	is_rectangle(char **map)
{
	int 	i;
	size_t 	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(map[0]);
	while (map[i])
	{
		if (i != 0)
		{
			j = ft_strlen(map[i]);
			if (j != k)
				return (0);
		}
		i++;
	}
	return (1);
}

static int count_chara(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])	
	{
		while (map[i][j])
		{
		if (map[i][j] == c)
			count++;
		j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

bool	check_chara(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while(map[i][j])
		{
		if (map[i][j] != '0' && map[i][j] != '1' \
		&& map[i][j] != 'C' && map[i][j] != 'E' \
		&& map[i][j] != 'P')
			return (0);
		j++;
		}
		j = 0;
		i++;
	}
	if (count_chara(map, 'E') != 1 \
	|| count_chara(map, 'P') != 1 \
	|| count_chara(map, 'C' == 0))
		return (0);
	return (1);
}
