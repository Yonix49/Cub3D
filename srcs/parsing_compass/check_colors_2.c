/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:29:52 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 14:56:49 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	check_orientation(t_data *data, int *i)
{
	int	flag;

	flag = 0;
	flag = checking_compass(data, i, flag);
	if ((ft_strncmp("F ", data->map_compass[*i], 2) == 0))
	{
		if (check_floor(data, i) != 0)
			return (3);
		flag++;
	}
	else if (ft_strncmp("C ", data->map_compass[*i], 2) == 0)
	{
		if (check_ceiling(data, i) != 0)
			return (3);
		flag++;
	}
	if (flag == 0)
		return (ft_putstr_fd(2, "Error\nOrientation elements not good"), 8);
	return (0);
}

int	check_floor(t_data *data, int *i)
{
	if (is_valid_colors(data->map_compass[*i], 'F') != 0
		|| count_char(data->map_compass[*i], ',') != 2)
	{
		ft_putstr_fd(2, "Error\nNot valid colors cord found");
		return (2);
	}
	if (check_value_colors(data, i) != 0)
		return (2);
	if (stock_colors_f_rgb(data, i) != 0)
		return (3);
	return (0);
}

int	check_ceiling(t_data *data, int *i)
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
		return (2);
	if (stock_colors_c_rgb(data, i) != 0)
		return (3);
	return (0);
}

void	stock_path(t_data *data, char *test, int *j)
{
	if (test && ft_strncmp("NO", test, 2) == 0)
		data->cord.path_texture_no = ft_strdup(test, data);
	else if (test && ft_strncmp("SO", test, 2) == 0)
		data->cord.path_texture_so = ft_strdup(test, data);
	else if (test && ft_strncmp("WE", test, 2) == 0)
		data->cord.path_texture_we = ft_strdup(test, data);
	else if (test && ft_strncmp("EA", test, 2) == 0)
		data->cord.path_texture_ea = ft_strdup(test, data);
	(*j)++;
}

int	check_compass(t_data *data, int *i, int *j, char *test)
{
	if (*j == 0)
	{
		if (check_orientation(data, i) != 0)
			return (2);
		stock_path(data, test, j);
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
		(*j)++;
	}
	else if (*j == 3)
	{
		if (check_orientation(data, i) != 0)
			return (5);
		(*j)++;
	}
	return (0);
}
