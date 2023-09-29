/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:42:57 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 14:59:09 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	check_colors(t_data *data, int *i, int *j)
{
	if (*j == 4)
	{
		if (check_orientation(data, i) != 0)
			return (2);
		(*j)++;
	}
	else if (*j == 5)
	{
		if (check_orientation(data, i) != 0)
			return (2);
		(*j)++;
	}
	return (0);
}

char	*ft_verif(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}

int	stock_colors_c_rgb(t_data *data, int *i)
{
	char	*verif;
	int		x;

	x = 0;
	verif = ft_substr(data->map_compass[*i], ft_isnum(data->map_compass[*i]),
			(size_t)ft_strlen(data->map_compass[*i]), data);
	if (!verif)
		return (1);
	data->cc_rgb = ft_split(verif, ',', data);
	if (!data->cc_rgb)
		return (1);
	while (data->cc_rgb[x])
	{
		data->cc_rgb[x] = ft_verif(data->cc_rgb[x]);
		x++;
	}
	return (0);
}

int	stock_colors_f_rgb(t_data *data, int *i)
{
	char	*verif;
	int		x;

	x = 0;
	data->ff_rgb = NULL;
	verif = ft_substr(data->map_compass[*i], ft_isnum(data->map_compass[*i]),
			(size_t)ft_strlen(data->map_compass[*i]), data);
	if (!verif)
		return (1);
	data->ff_rgb = ft_split(verif, ',', data);
	if (!data->ff_rgb)
		return (1);
	while (data->ff_rgb[x])
	{
		data->ff_rgb[x] = ft_verif(data->ff_rgb[x]);
		x++;
	}
	return (0);
}

int	is_valid_colors(char *map, char c)
{
	int	i;

	i = 0;
	if (map[0] != c)
		return (1);
	else
		i++;
	while (map[i] != '\n')
	{
		while (map[i] && map[i] == ' ')
			i++;
		if (map[i] != ' ' && map[i] != ',' && !(map[i] >= '0' && map[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
