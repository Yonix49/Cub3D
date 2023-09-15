/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:27:22 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/15 19:55:52 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	verif_bords(char **map)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (map[p])
		p++;
	p--;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' || map[p][i] != '1')
			return (3);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (2);
		i++;
	}
	return (0);
}

int	verif_map(char **map)
{
	int	i;
	int	first_line_length;

	first_line_length = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_line_length)
			return (0);
		i++;
	}
	return (1);
}




