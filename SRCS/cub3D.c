/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/15 19:55:10 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "string.h"
char	**get_map(char **argv)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**map;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		line = ft_strjoin_1(line, tmp);
		free(tmp);
	}
	free(tmp);
	close(fd);
	if ((is_char_sett(line)) == 0)
	{
		free(line);
		return (NULL);
	}
	map = ft_split(line, '\n');
	free(line);
	return (map);
}

typedef struct s_compass
{
	int	i;
	int	w;
	int	s;
	int	n;
	int	e;
}		t_compass;

int	verif_elem_compass(char **map)
{
	t_compass	counts;
	int			j;
	int			i;

	counts.i = 0;
	counts.w = 0;
	counts.s = 0;
	counts.n = 0;
	counts.e = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W')
				counts.w++;
			else if (map[i][j] == 'S')
				counts.s++;
			else if (map[i][j] == 'N')
				counts.n++;
			else if (map[i][j] == 'E')
				counts.e++;
			j++;
		}
		i++;
	}
	if (counts.s > 1 || counts.w > 1 || counts.n > 1 || counts.e > 1)
	{
		printf("%d %d %d %d\n", counts.s, counts.w, counts.n, counts.e);
		printf("Error il doit y'avoir un élément de chaque\n");
		return (2);
	}
	return (0);
}
int	verif_element(char **map)
{
	int	p;
	int	i;

	i = 0;
	while (map[i])
	{
		p = 0;
		while (map[i][p])
		{
			if (map[i][p] != '1' && map[i][p] != '0' && map[i][p] != 'W'
				&& map[i][p] != 'E' && map[i][p] != 'S' && map[i][p] != 'N')
			{
				printf("Un element inconnu a ete trouve\n");
				return (3);
			}
			p++;
		}
		i++;
	}
	return (0);
}
int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if ((verif_namearg(argc, argv)) != 0 || verif_open(argv) != 0)
		return (4);
	map = get_map(argv);
	i = 0;
	if (verif_elem_compass(map) != 0)
		printf("not good");
	if (verif_bords(map) != 0)
		printf("not goodd");
	if (verif_element(map) != 0)
	{
		printf("not gooddd");
	}
	// while (map[i])
	// {
	// 	printf("map[%s]\n", map[i]);
	// 	i++;
	// }
	return (0);
}
