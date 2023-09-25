/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:23:19 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/25 15:19:53 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"
int	check_opening(char *path)
{
	// for (int i = 0; path[i]; i++)
	// printf("path==%c\n", path[i]);
	printf("%s\n", path);
	int	fd;
	if (path == NULL)
		return (3);
	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
	{
		return (2);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (2);
	close (fd);
	return (0);
}
int		check_texture(t_data *data)
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
	// t_compass counts;
	int j;
	int i;
	int flag;
	flag = 0;
	// counts.i = 0;
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