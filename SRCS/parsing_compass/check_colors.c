/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:02:07 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/23 19:08:15 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	check_colors(t_data *data, int *i, int *j)
{
	if (*j == 4)
	{
		if (ft_strncmp("F ", data->map_compass[*i], 2) != 0)
		{
			ft_putstr_fd(2, "Error\nNot F on floor F");
			return (9);
		}
		if (is_valid_colors(data->map_compass[*i], 'F') != 0
			|| count_char(data->map_compass[*i], ',') != 2)
		{
			ft_putstr_fd(2, "Error\nNot valid colors cord found");
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
			ft_putstr_fd(2, "Error\n Not C on ceiling\n");
			return (9);
		}
		if (is_valid_colors(data->map_compass[*i], 'C') != 0
			|| count_char(data->map_compass[*i], ',') != 2)
		{
			ft_putstr_fd(2, "Error\n Not valid colors cord found\n");
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
			(size_t)ft_strlen(data->map_compass[*i]), data);
	check = ft_split(verif, ',', data);
	while (check[p])
	{
		if (check[p] && !(ft_atoi(check[p]) >= 0 && ft_atoi(check[p]) <= 255))
		{
			ft_putstr_fd(2, "Error\nColors not between 0 and 255\n");
			return (3);
		}
		p++;
	}
	// ft_putstr_fd(2, "check between 0 and 255 good \n");
	return (0);
}
char	*get_sub(t_data *data, int *i)
{
	char	*test;

	test = NULL;
	test = ft_substr(data->map_compass[*i],
						ft_len_dot(data->map_compass[*i], '.'),
						(size_t)ft_strlen(data->map_compass[*i]) - 4,
						data);
	return (test);
}
int	check_orientation(t_data *data, int *i)
{
	int	flag;

	flag = 0;
	if (ft_strncmp("NO", data->map_compass[*i], 2) == 0)
	{
		data->cord.path_texture_no = get_sub(data, i);
		flag++;
	}
	else if (ft_strncmp("SO", data->map_compass[*i], 2) == 0)
	{
		data->cord.path_texture_so = get_sub(data, i);
		flag++;
	}
	else if (ft_strncmp("WE", data->map_compass[*i], 2) == 0)
	{
		data->cord.path_texture_we = get_sub(data, i);
		flag++;
	}
	else if (ft_strncmp("EA", data->map_compass[*i], 2) == 0)
	{
		data->cord.path_texture_ea = get_sub(data, i);
		flag++;
	}
	if (flag == 0)
	{
		ft_putstr_fd(2, "Error\nOrientation elements not good");
		return (8);
	}
	return (0);
}
void	stock_path(t_data *data, char *test)
{
	if (test && ft_strncmp("NO", test, 2) == 0)
	{
		data->cord.path_texture_no = ft_strdup(test, data);
		printf("jesuisla\n");
	}
	else if (test && ft_strncmp("SO", test, 2) == 0)
		data->cord.path_texture_so = ft_strdup(test, data);
	else if (test && ft_strncmp("WE", test, 2) == 0)
		data->cord.path_texture_we = ft_strdup(test, data);
	else if (test && ft_strncmp("EA", test, 2) == 0)
		data->cord.path_texture_ea = ft_strdup(test, data);
}
int	check_compass(t_data *data, int *i, int *j, char *test)
{
	if (*j == 0)
	{
		if (check_orientation(data, i) != 0)
			return (2);
		stock_path(data, test);
		(*j)++;
	}
	else if (*j == 1)
	{
		if (check_orientation(data, i) != 0)
			return (3);
		(*j)++;
	}
	else if (*j == 2)
	{
		if (check_orientation(data, i) != 0)
			return (3);
		i(*j)++;
	}
	else if (*j == 3)
	{
		if (check_orientation(data, i) != 0)
			return (5);
		(*j)++;
	}
	return (0);
}
