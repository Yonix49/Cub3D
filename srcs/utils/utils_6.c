/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:48:01 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 18:13:14 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

unsigned int	ft_len_dot(char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_count_games(char **map, int count_games)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				count_games++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (count_games);
}

int	get_grande(char **map)
{
	int	a;
	int	grande;
	int	x;

	a = 0;
	grande = 0;
	x = 0;
	while (map[x])
	{
		a = ft_strlen(map[x]);
		if (grande < a)
		{
			grande = a;
		}
		x++;
	}
	grande--;
	return (grande);
}
