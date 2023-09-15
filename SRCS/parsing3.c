/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:37:55 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/15 19:56:26 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	is_char_sett(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || ft_strlen(map) < 3 || (map[i] == '\n' && map[i
					+ 1] == '\n'))
		{
			write(2, "Error\nSpace", 12);
			return (0);
		}
		i++;
	}
	return (9999);
}

int	verifall(char **map)
{

	if (!(verif_bords(map) == 1))
	{
		write(2, "Error\nMur", 10);
		return (0);
	}
	else if (!(verif_map(map) == 1))
	{
		write(2, "Error\nLa map n'est pas rectangulaire", 37);
		return (0);
	}
	return (1);
}

int	verif_exit(char **map)
{
	int	i;
	int	y;

	i = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == 'E')
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}
