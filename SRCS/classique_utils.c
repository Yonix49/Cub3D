/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classique_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:11:08 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/19 12:11:52 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	int				res;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (sign * res);
}

unsigned int	ft_isnum(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (i);
		i++;
	}
	return (i);
}
unsigned int	count_char(char *str, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j++;
		}
		i++;
	}
	return (j);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]) && i < n - 1)
	{
		i++;
	}
	if (s1[i] - s2[i] < -127)
		return (-(s1[i] - s2[i]));
	return (s1[i] - s2[i]);
}