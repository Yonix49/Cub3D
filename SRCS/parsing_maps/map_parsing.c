/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:36:40 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/22 15:40:54 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	parsing_map_wall(t_data *data)
{
	if (map_got_void(data->map_wall) != 0)
		return (3);
	if (verif_element_of_map(data->map_wall) != 0)
		return (2);
	if (verif_larg(data->map_wall) != 0)
		return (3);
	if (verif_bords(data->map_wall) != 0)
		return (8);
	if (verif_elem_compass(data) != 0)
		return (6);
	if (get_map_for_game(data->map_wall, data))
		return (8);
	if (arounded_player(data->map_ray, data) != 0)
		return (4);
	return (0);
}

int	map_got_void(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][0] == '\n')
		i++;
	while (map[i])
	{
		if (map[i][0] == '\0' || map[i][0] == '\n')
		{
			printf("error\n wrong char in map");
			return (4);
		}
		i++;
	}
	return (0);
}

int	verif_larg(char **map)
{
	int	i;
	int	p;
	int	x;

	x = 0;
	p = 0;
	i = 0;
	while (map[p])
	{
		if (it_is_this_char(map[p], '1') == 1)
		{
			break ;
		}
		p++;
	}
	while (map[x])
		x++;
	x--;
	while (map[p][i] != '\0')
	{
		if (map[p][i] != '1' && map[p][i] != '\n' && map[p][i] != ' '
			&& map[p][i] != '\0')
		{
			printf("Error: first line map incorrect\n");
			return (8);
		}
		if (map[x][i] != '1' && map[x][i] != '\n' && map[x][i] != ' '
			&& map[x][i] != '\0')
		{
			printf("Error: last line map incorrect\n");
			return (2);
		}
		i++;
	}
	return (0);
}

int	verif_bords(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (!map[i][j] || (map[i][j] != '1' && map[i][j] != '\n'))
		{
			printf("Error: caractère invalide dans la première colonne\n");
			return (1);
		}
		if (ft_strlen(map[i]) >= 2 &&
			(map[i][ft_strlen(map[i]) - 2] != '1' &&
				map[i][ft_strlen(map[i]) - 2] != '\n' &&
				map[i][ft_strlen(map[i]) - 2] != '\0'))
		{
			printf("Error: caractère invalide dans la dernière colonne\n");
			return (1);
		}
		i++;
	}
	return (0);
}