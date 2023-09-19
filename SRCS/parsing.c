/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:27:22 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/19 13:36:59 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"



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




