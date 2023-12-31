/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:13:22 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 15:17:58 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	get_different_maps(t_data *data, char **argv)
{
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd <= 0)
	{
		ft_putstr_fd(2, "Error\nOuverture fichier\n");
		return (2);
	}
	data->map = get_map(NULL, 0, data->map, data);
	if (!data->map)
		return (3);
	data->map_compass = get_cord_map(data->map, data);
	if (!data->map_compass)
		return (4);
	close(data->fd);
	return (0);
}

char	**get_cord_map(char **map, t_data *data)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	dest = NULL;
	while (map[i])
		i++;
	dest = ft_malloc(sizeof(char **) * (i + 1), data);
	if (!dest)
		return (NULL);
	i = 0;
	while (map[i] && j < 6)
	{
		if (map[i][0] != '\0' && map[i][0] != ' ' && map[i][0] != '\n')
		{
			dest[j] = ft_strdup(map[i], data);
			j++;
		}
		i++;
	}
	dest[j] = NULL;
	data->map_wall = get_wall(map, i, data);
	return (dest);
}

char	**get_map(char *line, int i, char **map, t_data *data)
{
	while (1)
	{
		line = ft_strdup("", data);
		line = get_next_line(data->fd, data);
		if (!line)
			break ;
		if (i == 0 && ft_count_space(line) == ft_strlen(line))
			continue ;
		if (*(line + ft_count_space(line)) == '\0' && i == 0)
			continue ;
		map = realloc_map(map, sizeof(char *) * (i + 1), sizeof(char *) * (i
					+ 2), data);
		if (!map)
			return (0);
		line[ft_strlen(line)] = '\0';
		map[i++] = line;
		map[i] = NULL;
		if (i == 0)
			ft_putstr_fd(2, "Error\n Map not valid");
	}
	return (map);
}

char	**get_wall(char **map, int i, t_data *data)
{
	int		j;
	char	**dest;

	j = 0;
	dest = NULL;
	while (map[j])
		j++;
	dest = ft_malloc(sizeof(char **) * (j - i + 1), data);
	if (!dest)
		return (NULL);
	j = 0;
	while (map[i])
	{
		dest[j] = ft_strdup(map[i], data);
		i++;
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
