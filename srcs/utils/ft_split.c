/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:12:33 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 18:09:38 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	numbrers_words(char *str, char c, size_t t)
{
	size_t	i;
	int		nb_words;

	i = 0;
	nb_words = 0;
	while (i < t && str[i])
	{
		if (str[i] != c && ((i == 0 || str[i - 1] == c)))
			nb_words++;
		i++;
	}
	return (nb_words);
}

static int	word_len(char *str, int i, char c)
{
	int	z;

	z = 0;
	while (str[i] && str[i] != c)
	{
		z++;
		i++;
	}
	return (z);
}

static void	assemblage(char **tab, char *str, int i, t_data *data)
{
	int	k;
	int	j;

	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] == data->c)
			i++;
		if (str[i])
		{
			tab[j] = (char *)ft_malloc(sizeof(char) * (word_len(str, i, data->c)
						+ 1), data);
			while (str[i] && str[i] != data->c)
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
}

char	**ft_split(char *s, char c, t_data *data)
{
	char	*str;
	char	**tab;
	int		i;

	data->c = c;
	i = 0;
	str = (char *)s;
	tab = ft_malloc(sizeof(char *) * (numbrers_words(str, c, ft_strlen(str))
				+ 1), data);
	if (!tab)
		return (NULL);
	assemblage(tab, str, i, data);
	return (tab);
}

// int main ()
// {
// 	char **tab;
// const char s [] = "1111111111111111111111111111111111
// 1E0000000000000C00000C000000000001
// 1010010100100000101001000000010101
// 1010010010101010001001000000010101
// 1P0000000C00C0000000000000000000C1
// 1111111111111111111111111111111111";
// 	char c = ' ';
// 	int i;
// 	i = 0;
// 	tab = ft_split(s, c);
// 	while(i < 8)
// 	{
// 		printf("tab[%d] = %s\n" , i , tab[i]);
// 		i++;
// 	}
// 	return (0);
// }