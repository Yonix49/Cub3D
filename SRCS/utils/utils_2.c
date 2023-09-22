/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:07:18 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/22 14:49:56 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"


void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	print_mouvement(t_data *img)
{
	write(1, "nb mouvement == ", 16);
	ft_putnbr_fd(img->nb_mouvement, 1);
	write(1, "\n", 1);
}
