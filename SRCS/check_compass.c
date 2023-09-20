/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:23:19 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/20 17:44:42 by mhajji-b         ###   ########.fr       */
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

int	verif_elem_compass(t_data *data)
{
	t_compass	counts;
	int			j;
	int			i;
	int 		flag;
	flag = 0;
	counts.i = 0;
	i = 0;
	while (data->map_wall[i])
	{
		j = 0;
		while (data->map_wall[i][j])
		{
			if (data->map_wall[i][j] == 'W')
				flag++;
			else if (data->map_wall[i][j] == 'S')
				flag++;
			else if (data->map_wall[i][j] == 'N')
				flag++;
			else if (data->map_wall[i][j] == 'E')
				flag++;
			j++;
		}
		i++;
	}
	if (!(flag == 1))
	{
		printf("Error\n il doit y'avoir un seul element d'orientation");
		return (2);
	}
	return (0);
}