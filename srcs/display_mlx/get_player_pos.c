/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:32:17 by kgezgin           #+#    #+#             */
/*   Updated: 2023/09/28 14:04:42 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static void	set_south_or_north(char c, t_data *data)
{
	if (c == 'S')
	{
		data->all->dir_x = 0.99;
		data->all->plane_x = 0;
		data->all->dir_y = 0;
		data->all->plane_y = -0.6;
	}
	else if (c == 'N')
	{
		data->all->dir_x = -0.99;
		data->all->plane_x = 0;
		data->all->dir_y = 0;
		data->all->plane_y = 0.6;
	}
}

static void	set_west_or_east(char c, t_data *data)
{
	if (c == 'W')
	{
		data->all->dir_x = 0;
		data->all->plane_x = -0.6;
		data->all->dir_y = -0.99;
		data->all->plane_y = 0;
	}
	else if (c == 'E')
	{
		data->all->dir_x = 0;
		data->all->plane_x = 0.6;
		data->all->dir_y = 0.99;
		data->all->plane_y = 0;
	}
}

int	get_player_pos(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				data->all->pos_x = i + 0.5;
				data->all->pos_y = j + 0.5;
				if (map[i][j] == 'S' || map[i][j] == 'N')
					set_south_or_north(map[i][j], data);
				if (map[i][j] == 'W' || map[i][j] == 'E')
					set_west_or_east(map[i][j], data);
				map[i][j] = 0;
				break ;
			}
		}
	}
	return (1);
}
