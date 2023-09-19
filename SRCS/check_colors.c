/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:02:07 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/19 12:07:35 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	check_colors(t_data *data, int *i, int *j)
{
	if (*j == 4)
	{
		if (ft_strncmp("F ", data->map_compass[*i], 2) != 0)
		{
			printf("Error not F on floor F\n");
			return (9);
		}
		if (is_valid_colors(data->map_compass[*i], 'F') != 0
			|| count_char(data->map_compass[*i], ',') != 2)
		{
			printf("not valid colors cord found\n");
			return (2);
		}
		if (check_value_colors(data, i) != 0)
		{
			return (2);
		}
		(*j)++;
	}
	else if (*j == 5)
	{
		if (ft_strncmp("C ", data->map_compass[*i], 2) != 0)
		{
			printf("Error not C on ceiling\n");
			return (9);
		}
		if (is_valid_colors(data->map_compass[*i], 'C') != 0
			|| count_char(data->map_compass[*i], ',') != 2)
		{
			printf("not valid colors cord found\n");
			return (2);
		}
		if (check_value_colors(data, i) != 0)
		{
			return (2);
		}
		(*j)++;
	}
	printf("check_colors good\n");
	return (0);
}
int	is_valid_colors(char *map, char c)
{
	int	i;

	i = 0;
	if (map[0] != c)
	{
		printf("je suis la char == %c\n", map[i]);
		return (1);
	}
	else
		i++;
	while (map[i] != '\n')
	{
		while (map[i] && map[i] == ' ')
			i++;
		if (map[i] != ' ' && map[i] != ',' && !(map[i] >= '0' && map[i] <= '9'))
		{
			printf("je suis la char == %c\n", map[i]);
			return (1);
		}
		i++;
	}
	return (0);
}
int	check_value_colors(t_data *data, int *i)
{
	char	*verif;
	char	**check;
	int		p;

	check = NULL;
	p = 0;
	verif = ft_substr(data->map_compass[*i], ft_isnum(data->map_compass[*i]),
			(size_t)ft_strlen(data->map_compass[*i]));
	check = ft_split(verif, ',');
	while (check[p])
	{
		printf("check[%s] \n", check[p]);
		if (!(ft_atoi(check[p]) >= 0 && ft_atoi(check[p]) <= 255))
		{
			printf("Colors not between 0 and 255\n");
			return (3);
		}
		p++;
	}
	printf("check between 0 and 255 good \n");
	return (0);
}

int	check_compass(t_data *data, int *i, int *j, char *test)
{
	if (*j == 0)
	{
		if (ft_strncmp("NO", data->map_compass[*i], 2) != 0)
		{
			printf("Error\n");
			printf("NO");
			return (9);
		}
		test = ft_substr(data->map_compass[*i],
							ft_len_dot(data->map_compass[*i], '.'),
							(size_t)ft_strlen(data->map_compass[*i]));
		(*j)++;
	}
	else if (*j == 1)
	{
		if (ft_strncmp("SO", data->map_compass[*i], 2) != 0)
		{
			printf("Error\n");
			printf("SO");
			return (9);
		}
		test = ft_substr(data->map_compass[*i],
							ft_len_dot(data->map_compass[*i], '.'),
							(size_t)ft_strlen(data->map_compass[*i]));
		(*j)++;
	}
	else if (*j == 2)
	{
		if (ft_strncmp("WE", data->map_compass[*i], 2) != 0)
		{
			printf("Error\n");
			printf("WE");
			return (9);
		}
		test = ft_substr(data->map_compass[*i],
							ft_len_dot(data->map_compass[*i], '.'),
							(size_t)ft_strlen(data->map_compass[*i]));
		(*j)++;
	}
	else if (*j == 3)
	{
		if (ft_strncmp("EA", data->map_compass[*i], 2) != 0)
		{
			printf("Error\n");
			printf("EA");
			return (9);
		}
		test = ft_substr(data->map_compass[*i],
							ft_len_dot(data->map_compass[*i], '.'),
							(size_t)ft_strlen(data->map_compass[*i]));
		(*j)++;
	}
	return (0);
}
