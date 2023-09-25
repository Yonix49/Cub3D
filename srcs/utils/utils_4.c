/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:27:10 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/22 14:50:01 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

char	*ft_strdup_for_ray(char *src, int grande, t_data *data)
{
	int		i;
	int		src_len;
	char	*dest;
	int		src_index;

	i = 0;
	src_len = ft_strlen(src);
	dest = ft_malloc(sizeof(char) * (grande + 1), data);
	if (!dest)
		return (NULL);
	src_index = 0;
	while (i < grande)
	{
		if (src_index >= src_len)
			dest[i] = '0';
		else if (src[src_index] == '\n' || src[src_index] == ' ')
			dest[i] = '0';
		else
			dest[i] = src[src_index];
		src_index++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
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