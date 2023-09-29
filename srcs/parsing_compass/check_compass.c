/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:23:19 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 16:44:25 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	check_opening(char *path)
{
	int	fd;

	if (path == NULL)
		return (3);
	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
		return (2);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (2);
	close(fd);
	return (0);
}

int	check_texture(t_data *data)
{
	if (check_opening(data->cord.path_texture_no) != 0)
		return (4);
	if (check_opening(data->cord.path_texture_so) != 0)
		return (4);
	if (check_opening(data->cord.path_texture_we) != 0)
		return (4);
	if (check_opening(data->cord.path_texture_ea) != 0)
		return (4);
	return (0);
}

int	check_all_compass(t_data *data)
{
	if (parsing_compass(data) != 0)
		return (9);
	if (check_texture(data) != 0)
	{
		ft_putstr_fd(2, "Error\nOpening pack texture");
		return (3);
	}
	return (0);
}

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
	if (parsing_compass_2(data, i, j) != 0)
		return (8);
	return (0);
}

int	parsing_compass_2(t_data *data, int i, int j)
{
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
