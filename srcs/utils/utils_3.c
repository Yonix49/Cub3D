/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:44:58 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 18:11:59 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*i;

	i = s;
	while (n > 0)
	{
		*i = c;
		i++;
		n--;
	}
	return (s);
}

size_t	ft_securite(size_t nmemb, size_t size)
{
	size_t	size_max;

	size_max = LONG_MAX;
	if (nmemb == 0 || size == 0)
		return (0);
	if (nmemb > size_max / size || size > size_max / nmemb)
		return (LONG_MAX);
	return (nmemb * size);
}

void	*ft_calloc(size_t nmemb, size_t size, t_data *data)
{
	unsigned char	*tab;

	tab = ft_malloc(ft_securite(nmemb, size), data);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, ft_securite(nmemb, size));
	return (tab);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
