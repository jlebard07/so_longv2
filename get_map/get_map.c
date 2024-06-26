/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlebard <jlebard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:03:25 by jlebard           #+#    #+#             */
/*   Updated: 2024/06/12 18:03:25 by jlebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_bool_tab(bool **bool_tab)
{
	int	i;

	i = 0;
	while (bool_tab[i])
	{
		free(bool_tab[i]);
		i++;
	}
	free(bool_tab);
}

static char	*get_buffer(char *map_path)
{
	int		fd;
	char	*buffer;
	char	*line;
	char	*temp;

	buffer = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (buffer == NULL)
			buffer = ft_strdup(line);
		else
		{
			temp = ft_strjoin(buffer, line);
			free(buffer);
			buffer = temp;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (buffer);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	**parse_and_check(char *map_path)
{
	char	**map;
	int		i;
	char	*buffer;

	i = 0;
	buffer = get_buffer(map_path);
	if (buffer == NULL || buffer[0] == '\0')
	{
		ft_putstr_fd("Error :\nErreur lors de l'ouverture du fichier \
		/ map vide\n", 2);
		exit (1);
	}
	map = ft_split(buffer, '\n');
	free(buffer);
	while (map[i])
		i++;
	if (i < 3 || check_chara(map) == 0 || check_wall(map) == 0 \
	|| is_rectangle(map) == 0)
	{
		free_map(map);
		ft_putstr_fd("Error :\nMauvais format", 2);
		exit (1);
	}
	return (map);
}
