/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:32:17 by kgezgin           #+#    #+#             */
/*   Updated: 2023/09/25 17:37:40 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

static void	set_south_or_north(char c, t_all *all)
{
	if (c == 'S')
	{
		all->dir_x = 0.99;
		all->plane_x = 0;
		all->dir_y = 0;
		all->plane_y = -0.6;
	}
	else if (c == 'N')
	{
		all->dir_x = -0.99;
		all->plane_x = 0;
		all->dir_y = 0;
		all->plane_y = 0.6;
	}
}

static void	set_west_or_east(char c, t_all *all)
{
	if (c == 'W')
	{
		all->dir_x = 0;
		all->plane_x = -0.6;
		all->dir_y = -0.99;
		all->plane_y = 0;
	}
	else if (c == 'E')
	{
		all->dir_x = 0;
		all->plane_x = 0.6;
		all->dir_y = 0.99;
		all->plane_y = 0;
	}
}

void	get_player_pos(char **map, t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				all->pos_x = i + 0.5;
				all->pos_y = j + 0.5;
				if (map[i][j] == 'S' || map[i][j] == 'N')
					set_south_or_north(map[i][j], all);
				if (map[i][j] == 'W' || map[i][j] == 'E')
					set_west_or_east(map[i][j], all);
				map[i][j] = 0;
				break ;
			}
		}
	}
	return (1);
}
