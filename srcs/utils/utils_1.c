/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:48:49 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/28 18:10:20 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
	{
		i++;
	}
	if (s1[i] - s2[i] < -127)
		return (-(s1[i] - s2[i]));
	return (s1[i] - s2[i]);
}

char	*ft_strjoin_1(char *s1, char *s2, t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s1 && s2 && *s2)
		return (ft_strdup(s2, data));
	if (!s2)
		return (NULL);
	str = (char *)ft_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1),
			data);
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_putnbr(int n, int fd)
{
	long int	nb;

	nb = (long int)n;
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar_fd(nb + 48, fd);
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr(nb * (-1), fd);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
	return (0);
}
