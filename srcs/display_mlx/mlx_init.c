/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2123/09/25 11:41:59 by kgezgin           #+#    #+#             */
/*   Updated: 2023/09/25 17:47:03 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"


int	start_mlx(t_data *data)
{
	get_player_pos(data->map_ray, data->all);
	data->all->mlx = mlx_init();
	if (!data->all->mlx)
		return (1);
	data->all->win = mlx_new_window(data->all->mlx, 720, 1080, "Cub3D");
	if (!data->all->win)
		return (ft_putstr_fd(2, "Error\nFailed to create window\n"), 1);
	if (!set_images(data))
		return (ft_putstr_fd(2, "Error\nFailed to set images\n"), 1);
	mlx_loop_hook(data->all->mlx, &main_loop, &data);
	mlx_hook(data->all->win, 17, 0, mlx_loop_end, data->all->mlx);
	// mlx_hook(info.win, 2, (1L << 0), key_press, &info);
	mlx_loop(data->all->mlx);
	// info_free(&info);
		
		
	return (0);
}

int	main_loop(t_data *data)
{
	calcul(data);
	draw(data);
	return (0);
}

int	malloc_texture2(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		data->all->textures[i] = ft_malloc(sizeof(int) * (64 * 64), data->d_mem);
		if (!data->all->textures[i])
			return (0);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < (64 * 64))
			data->all->textures[i][j] = 0;
	}
	return (1);
}

int	malloc_textures(t_data	*data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			data->all->buf[i][j] = 0;
	}
	data->all->textures = ft_malloc(sizeof(int *) * 4, data->d_mem);
	if (!data->all->textures)
		return (0);
	if (!malloc_texture2(data))
		return (0);
	return (1);
}
