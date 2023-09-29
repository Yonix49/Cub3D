/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:36:40 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 18:02:41 by mhajji-b         ###   ########.fr       */
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
	while (map[i] && map[i][0] == '\n')
		i++;
	if (!map[i])
		return (ft_putstr_fd(2, "Error\nEmpty map"), 2);
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'W' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != '0')
				return (ft_putstr_fd(2, "Error\nWrong char in map"), 4);
			else if (map[i][0] == '\n')
				return (ft_putstr_fd(2, "Error\nGot void in map"), 4);
			j++;
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
			break ;
		p++;
	}
	while (map[x])
		x++;
	x--;
	if (verif_large_2(map, x, p, i) != 0)
		return (3);
	return (0);
}

int	verif_large_2(char **map, int x, int p, int i)
{
	while (map[p][i] != '\0')
	{
		if (map[p] && map[p][i] != '1' && map[p][i] != '\n' && map[p][i] != ' '
			&& map[p][i] != '\0')
			return (ft_putstr_fd(2, "Error\nFirst line map incorrect\n"), 8);
		i++;
	}
	i = 0;
	while (map[x][i] != '\0')
	{
		if (map[x][0] != '\0' && map[x] && map[x][i] != '1' && map[x][i] != '\n'
			&& map[x][i] != ' ')
		{
			if (map[x][0] != '\0' && map[x][i] != '1' && map[x][i] != '\n')
				return (ft_putstr_fd(2, "Error\nLast line map incorrect\n"), 2);
		}
		i++;
	}
	return (0);
}

int	verif_bords(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (!map[i][j] || (map[i][j] != '1' && map[i][j] != '\n'))
			return (ft_putstr_fd(2, "Error\nChar wrong first linen"), 1);
		if (ft_strlen(map[i]) >= 2 && (map[i][ft_strlen(map[i]) - 2] != '1'
			&& map[i][ft_strlen(map[i]) - 2] != '\n'
			&& map[i][ft_strlen(map[i]) - 2] != '\0'))
			return (ft_putstr_fd(2, "Error\nChar wrong last line \n"), 1);
		i++;
	}
	return (0);
}
