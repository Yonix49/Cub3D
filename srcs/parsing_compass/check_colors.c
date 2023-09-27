/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:02:07 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/27 17:03:07 by kgezgin          ###   ########.fr       */
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
		if (stock_colors_f_rgb(data, i) != 0)
			return (3);
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
		if (stock_colors_c_rgb(data, i) != 0)
			return (3);
		(*j)++;
	}
	// put_rgb_data(data);
	// for (int x = 0; data->cc_rgb[x]; x++)
	// 	printf("cc [%s]\n", data->cc_rgb[x]);
	// data->f_rgb = 65536 * ft_atoi(data->cc_rgb[0]) + 256 * ft_atoi(data->cc_rgb[1]) + ft_atoi(data->cc_rgb[2]);
	// data->c_rgb = 65536 * ft_atoi(data->cc_rgb[0]) + 256 * ft_atoi(data->cc_rgb[1]) + ft_atoi(data->cc_rgb[2]);
	// dprintf(1, "data->f_rgb = %d\n", data->f_rgb);
	// dprintf(1, "data->c_rgb = %d\n", data->c_rgb);
	printf("check_colors good\n");
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
	// data->cc_rgb = NULL;
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
	// printf("cc [%s]\n", data->cc_rgb[0]);

	// for (int x = 0; data->cc_rgb[x]; x++)
	// 	printf("cc [%s]\n", data->cc_rgb[x]);
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
	
	// for (int x = 0; data->ff_rgb[x]; x++)
	// 	printf("ff [%s]\n", data->ff_rgb[x]);
	return (0);
}

// void	put_rgb_data(t_data *data)
// {
// 	// for (int x = 0; rgb[x]; x++)
// 	// 	printf("%s\n", rgb[x]);
// 	// data->cord.f_rgb = 65536 * ft_atoi(data->cc_rgb[0]) + 256 * ft_atoi(data->cc_rgb[1]) + ft_atoi(data->cc_rgb[2]);
// 	// data->cord.c_rgb = 65536 * ft_atoi(data->cc_rgb[0]) + 256 * ft_atoi(data->cc_rgb[1]) + ft_atoi(data->cc_rgb[2]);
// 	// dprintf(1, "data->cord.f_rgb = %d\n", data->cord.f_rgb);
// 	// dprintf(1, "data->cord.c_rgb = %d\n", data->cord.c_rgb);
// }

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
int	count_tab(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
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
	if ((count_tab(check) != 3))
	{
		ft_putstr_fd(2, "Error\nColors \n");
		return (1);
	}
	while (check[p])
	{
		if (check[p] && !(ft_atoi(check[p]) >= 0 && ft_atoi(check[p]) <= 255))
		{
			ft_putstr_fd(2, "Error\nColors not between 0 and 255\n");
			return (3);
		}
		p++;
	}
	return (0);
}

// int	colors_f_rgb(char **src, t_data *data)
// {
// 	int	i;

// 	// char	**dest;
// 	i = 0;
// 	data->all->c_rgb = ft_malloc(sizeof(char **) * (4), data);
// 	if (!data->all->c_rgb)
// 		return (2);
// 	while (src[i])
// 	{
// 		data->all->c_rgb[i] = ft_strdup(src[i], data);
// 		i++;
// 	}
// 	data->all->c_rgb[i] = NULL;
// 	return (0);
// }
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
