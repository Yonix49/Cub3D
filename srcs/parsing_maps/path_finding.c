/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:34:19 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 17:44:06 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	flood_recursively_to_border(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return (0);
	map[y][x] = '2';
	if (x == 0 || y == 0 || map[y + 1] == NULL || map[y][x + 1] == '\0')
		return (1);
	if (flood_recursively_to_border(map, x + 1, y))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y))
		return (1);
	if (flood_recursively_to_border(map, x, y + 1))
		return (1);
	if (flood_recursively_to_border(map, x, y - 1))
		return (1);
	if (flood_recursively_to_border(map, x + 1, y + 1))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y - 1))
		return (1);
	if (flood_recursively_to_border(map, x + 1, y - 1))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y + 1))
		return (1);
	return (0);
}

char	**copied_map(char **map, t_data *data)
{
	int		i;
	char	**cop_map;

	cop_map = NULL;
	i = 0;
	while (map[i])
		i++;
	cop_map = ft_malloc(sizeof(char *) * (i + 1), data);
	if (!cop_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		cop_map[i] = ft_strdup(map[i], data);
		i++;
	}
	cop_map[i] = NULL;
	return (cop_map);
}

int	arounded_player(char **map, t_data *data)
{
	int		i;
	int		j;
	char	**map_copie;

	i = 0;
	map_copie = copied_map(map, data);
	if (!map_copie)
		return (3);
	while (map_copie[i])
	{
		j = 0;
		while (map_copie[i][j])
		{
			if (map_copie[i][j] == 'N' || map_copie[i][j] == 'S'
				|| map_copie[i][j] == 'W' || map_copie[i][j] == 'E')
			{
				if (flood_recursively_to_border(map_copie, j, i))
					return (ft_putstr_fd(2, "Error\n invalid borders"), 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
