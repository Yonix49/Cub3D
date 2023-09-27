/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2123/09/25 11:41:59 by kgezgin           #+#    #+#             */
/*   Updated: 2023/09/27 17:43:54 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

// t_all	*all_init(void)
// {
	// t_all *all;
// 
// }

int	start_mlx(t_data *data)
{
	data->all = ft_malloc(sizeof(t_all), data);
	data->all->pos_x = 0;
	data->all->pos_y = 0;
	data->all->map_x = 0;
	data->all->map_y = 0;
	data->all->dir_x = 0;
	data->all->dir_y = 0;
	data->all->delta_distx = 0;
	data->all->delta_disty = 0;
	data->all->side_distx = 0;
	data->all->side_disty = 0;
	data->all->perp_wall_dist = 0;
	data->all->plane_x = 0;
	data->all->plane_y = 0;
	data->all->ray_dirx = 0;
	data->all->ray_diry = 0;
	data->all->wall_x = 0;
	data->all->move_speed = 0.099;
	data->all->rot_speed = 0.09;
	data->all->side = 0;
	data->all->tex_x = 0;
	data->all->tex_width = 64;
	data->all->tex_height = 64;
	// data->all->line_height = 
	get_player_pos(data->map_ray, data);
	data->all->mlx = mlx_init();
	if (!data->all->mlx)
		return (1);
	data->all->win = mlx_new_window(data->all->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->all->win)
		return (ft_putstr_fd(2, "Error\nFailed to create window\n"), 1);
	if (!set_images(data))
		return (ft_putstr_fd(2, "Error\nFailed to set images\n"), 1);
	mlx_loop_hook(data->all->mlx, &main_loop, &data);
	mlx_hook(data->all->win, 17, 0, mlx_loop_end, data->all->mlx);
	mlx_hook(data->all->win, 2, (1L << 0), key_press, &data);
	mlx_loop(data->all->mlx);
	data_free(data);
	return (0);
}

int	data_free(t_data *data)
{
	mlx_destroy_image(data->all->mlx, data->all->img.img);
	if (data->all->win)
	{
		mlx_clear_window(data->all->mlx, data->all->win);
		mlx_destroy_window(data->all->mlx, data->all->win);
	}
	if (data->all->mlx)
	{
		mlx_destroy_display(data->all->mlx);
		free(data->all->mlx);
	}
	return (0);
}

int	main_loop(t_data **data)
{
	calcul(data);
	draw(*data);
	return (0);
}

int	malloc_texture2(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		data->all->textures[i] = ft_malloc(sizeof(int) * (64 * 64), data);
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
	data->all->textures = ft_malloc(sizeof(int *) * 4, data);
	if (!data->all->textures)
		return (0);
	if (!malloc_texture2(data))
		return (0);
	return (1);
}
