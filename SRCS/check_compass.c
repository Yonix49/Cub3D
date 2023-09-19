/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:23:19 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/19 12:24:04 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
int	parsing_compass(t_data *data)
{
	int		i;
	int		j;
	char	*test;

	test = NULL;
	j = 0;
	i = 0;
	while (data->map_compass[i] && j < 4)
	{
		if (data->map_compass[i][1] != '\0' && j < 4)
		{
			if (check_compass(data, &i, &j, test) != 0)
				return (9);
		}
		i++;
	}
	while (data->map_compass[i] && j < 6)
	{
		if (data->map_compass[i][1] != '\0' && j < 6)
		{
			if (check_colors(data, &i, &j) != 0)
				return (10);
		}
		i++;
	}
	return (0);
}

int	verif_elem_compass(char **map)
{
	t_compass	counts;
	int			j;
	int			i;

	counts.i = 0;
	counts.w = 0;
	counts.s = 0;
	counts.n = 0;
	counts.e = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W')
				counts.w++;
			else if (map[i][j] == 'S')
				counts.s++;
			else if (map[i][j] == 'N')
				counts.n++;
			else if (map[i][j] == 'E')
				counts.e++;
			j++;
		}
		i++;
	}
	if (counts.s > 1 || counts.w > 1 || counts.n > 1 || counts.e > 1)
	{
		printf("%d %d %d %d\n", counts.s, counts.w, counts.n, counts.e);
		printf("Error il doit y'avoir un élément de chaque\n");
		return (2);
	}
	return (0);
}