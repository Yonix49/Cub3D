/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/19 20:39:15 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "string.h"

int	ft_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_count_space(char *line)
{
	int	i;

	i = 0;
	while (ft_space(line[i]))
		i++;
	return (i);
}

void	*realloc_map(void *ptr, size_t ptrsize, size_t newsize)
{
	void	*newptr;

	if (ptr == NULL)
		return (ft_calloc(newsize, 1));
	if (newsize == 0)
		return (free(ptr), NULL);
	if (newsize <= ptrsize)
		return (ptr);
	newptr = ft_calloc(newsize, 1);
	if (!newptr)
		return (NULL);
	ft_memcpy(newptr, ptr, ptrsize);
	free(ptr);
	return (newptr);
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

int	init_data(t_data *data)
{
	ft_memset((data), 0, sizeof(t_data));
	// data->map_compass = NULL;
	// data->map = NULL;
	return (0);
}

unsigned int	ft_len_dot(char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}
int	map_got_void(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][0] == '\n')
		i++;
	while (map[i])
	{
		if (map[i][0] == '\0' || map[i][0] == '\n')
		{
			printf("error space in map\n");
			return (4);
		}
		i++;
	}
	return (0);
}
int	it_is_this_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
int	verif_larg(char **map)
{
	int	i;
	int	p;
	int	x;

	x = 0;
	p = 0;
	i = 0;
	while (map[p])
	{
		if (it_is_this_char(map[p], '1') == 1)
		{
			break ;
		}
		p++;
	}
	while (map[x])
		x++;
	x--;
	while (map[p][i] != '\0')
	{
		if (map[p][i] != '1' && map[p][i] != '\n' && map[p][i] != ' '
			&& map[p][i] != '\0')
		{
			printf("Error: first line map incorrect\n");
			return (3);
		}
		if (map[x][i] != '1' && map[x][i] != '\n' && map[x][i] != ' '
			&& map[x][i] != '\0')
		{
			printf("Error: last line map incorrect\n");
			return (3);
		}
		i++;
	}
	return (0);
}
unsigned int	first_char_line(char *map)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == ' ')
		{
			p++;
		}
		i++;
	}
	return (p);
}
unsigned int	ft_count_this(char *map)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] != '\n')
			p++;
		i++;
	}
	p--;
	return (p);
}

int	verif_bords(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
		{
			j++;
		}
		if ((map[i][j] != '1' && map[i][j] != '\n'))
		{
			printf("Error: caractère invalide dans la première colonne\n");
			return (1);
		}
		else if ((map[i][ft_strlen(map[i]) - 2] != '1')
				&& (map[i][ft_strlen(map[i]) - 2] != '\n')
				&& (map[i][ft_strlen(map[i]) - 2] != '\0'))
		{
			printf("Error \n caractère invalide dans la derniere colonne\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	parsing_map_wall(t_data *data)
{
	if (map_got_void(data->map_wall) != 0)
		return (3);
	if (verif_element_of_map(data->map_wall) != 0)
		return (2);
	if (verif_larg(data->map_wall) != 0)
		return (2);
	if (verif_bords(data->map_wall) != 0)
		return (8);
	return (0);
}
int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if ((verif_namearg(argc, argv)) != 0 || verif_open(argv) != 0)
		return (3);
	if (get_different_maps(&data, argv) != 0)
		return (4);
	// if (parsing_compass(&data) != 0)
	// 	return (5);
	if (parsing_map_wall(&data) != 0)
		return (6);
	// int i = 0;
	// printf("cord\n");
	// while (data.map_compass[i])
	// {
	// 	printf("%s", data.map_compass[i]);
	// 	i++;
	// }
	// printf("map\n");
	// while (data.map[i])
	// {
	// 	printf("%s", data.map[i]);
	// 	i++;
	// }
	// i = 0;
	// if (verif_elem_compass(map) != 0)
	// 	printf("not good");
	// if (verif_bords(map) != 0)
	// 	printf("not goodd");
	// if (verif_element(map) != 0)
	// {
	// 	printf("not gooddd");
	// }
	return (0);
}
