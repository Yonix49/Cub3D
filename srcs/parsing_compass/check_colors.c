/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:02:07 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 15:12:07 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

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

int	checking_compass(t_data *data, int *i, int flag)
{
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
	return (flag);
}

int	verif_elem_compass(t_data *data)
{
	int	j;
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (data->map_wall[i])
	{
		j = 0;
		while (data->map_wall[i][j])
		{
			if (data->map_wall[i][j] == 'W' || data->map_wall[i][j] == 'S'
				|| data->map_wall[i][j] == 'E' || data->map_wall[i][j] == 'N')
				flag++;
			j++;
		}
		i++;
	}
	if (!(flag == 1))
		return (ft_putstr_fd(2, "Error\nOnly one compass element!"), 2);
	return (0);
}
