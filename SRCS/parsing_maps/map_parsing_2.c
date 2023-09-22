/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:39:35 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/22 15:35:19 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	get_map_for_game(char **map, t_data *data)
{
	int	count_games;
	int	grande;

	count_games = 0;
	count_games = ft_count_games(map, count_games);
	if (count_games == 0)
		return (3);
	data->map_for_games = ft_malloc(sizeof(char *) * (count_games), data);
	if (!data->map_for_games)
		return (2);
	data->map_for_games = ft_copie_map(map, data);
	if (data->map_for_games == NULL)
		return (9);
	grande = get_grande(data->map_for_games);
	data->map_ray = get_final_map(grande, count_games, data->map_for_games, data);
	if (!data->map_ray)
		return (3);
	return (0);
}

char	**ft_copie_map(char **map, t_data *data)
{
	int		i;
	int		j;
	int		x;
	char	**copie_map;

	x = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				x++;
				break ;
			}
			j++;
		}
		i++;
	}
	copie_map = ft_malloc(sizeof(char *) * (x + 1), data);
	if (!copie_map)
		return (NULL);
	i = 0;
	x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				copie_map[x] = ft_strdup(map[i], data);
				x++;
				break ;
			}
			j++;
		}
		i++;
	}
	copie_map[x] = NULL;
	return (copie_map);
}

char	**get_final_map(int grande, int count_line, char **map, t_data *data)
{
	char **mapi;
	int len;
	int i;

	mapi = ft_malloc(sizeof(char **) * (count_line + 1), data);
	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		if (map[i][0] == '\0')
		{
			i++;
			continue ;
		}
		mapi[i] = ft_strdup_for_ray(map[i], grande, data);
		i++;
	}
	mapi[i] = NULL;
	return (mapi);
}

int	verif_element_of_map(char **map)
{
	int	p;
	int	i;

	i = 0;
	while (map[i])
	{
		p = 0;
		while (map[i][p] && map[i][p] != '\n')
		{
			if (map[i][p] != '1' && map[i][p] != '0' && map[i][p] != 'W'
				&& map[i][p] != 'E' && map[i][p] != 'S' && map[i][p] != 'N'
				&& map[i][p] != ' ')
			{
				printf("Error \n un element inconnu a ete trouve %c \n",
						map[i][p]);
				return (3);
			}
			p++;
		}
		i++;
	}
	return (0);
}