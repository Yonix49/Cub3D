/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:13:22 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/19 19:31:40 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	get_different_maps(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		printf("Erreur ouverture fichie\n");
		return (2);
	}
	data->map = get_map(NULL, fd, 0, data->map);
	data->map_compass = get_cord_map(data->map, data);
	return (0);
}

char	**get_cord_map(char **map, t_data *data)
{
	int		i;
	int		j;
	int		x;
	char	**dest;
	x = 0;
	i = 0;
	j = 0;
	dest = NULL;
	while (map[i] && j < 6)
	{
		if (map[i][1] != '\0')
			j++;
		i++;
	}
	dest = malloc(sizeof(char **) * i + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (i > j)
	{
		dest[j] = ft_strdup(map[j]);
		j++;
	}
	dest[j] = NULL;
	data->map_wall = get_wall(map, i);
	return (dest);
}

char	**get_map(char *line, int fd, int i, char **map)
{
	int	flag;

	flag = 0;
	while (1)
	{
		line = ft_strdup("");
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (i == 0 && ft_count_space(line) == ft_strlen(line))
			continue ;
		if (*(line + ft_count_space(line)) == '\0' && i == 0)
		{
			continue ;
		}
		map = realloc_map(map, sizeof(char *) * (i + 1), sizeof(char *) * (i
					+ 2));
		if (!map)
			return (0);
		line[ft_strlen(line)] = '\0';
		map[i++] = line;
		map[i] = NULL;
		if (i == 0)
			printf("not a valid map\n");
	}
	return (map);
}
char	**get_wall(char **map, int i)
{
	int		j;
	char	**dest;

	j = 0;
	dest = NULL;
	while (map[j])
	{
		j++;
	}
	dest = malloc(sizeof(char **) * (j - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (map[i - 1])
	{
		dest[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	dest[i] = NULL;
	return (dest);
}