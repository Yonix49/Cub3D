/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:06:02 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/27 15:37:07 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	draw(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	mlx_destroy_image(data->all->mlx, data->all->img.img);
	data->all->img.img = mlx_new_image(data->all->mlx, WIDTH, HEIGHT);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			data->all->img.data[y * WIDTH + x] = data->all->buf[y][x];
	}
	mlx_put_image_to_window(data->all->mlx, data->all->win, data->all->img.img, 0, 0);
}

int	get_num_tex(t_data *data)
{
	int	tex_num;

	tex_num = 0;
	if (data->all->side == 0 && data->all->map_x - data->all->pos_x >= 0)
		tex_num = 0;
	else if (data->all->side == 0 && data->all->map_x - data->all->pos_x < 0)
		tex_num = 1;
	else if (data->all->side == 1 && data->all->map_y - data->all->pos_y < 0)
		tex_num = 2;
	else if (data->all->side == 1 && data->all->map_y - data->all->pos_y >= 0)
		tex_num = 3;
	return (tex_num);
}

void	draw_utils(t_data *data, int step_x, int step_y)
{
	if (data->all->side == 0)
		data->all->perp_wall_dist = (data->all->map_x - data->all->pos_x + (1
					- step_x) / 2) / data->all->ray_dirx;
	else
		data->all->perp_wall_dist = (data->all->map_y - data->all->pos_y + (1
					- step_y) / 2) / data->all->ray_diry;
	data->all->line_height = (int)(HEIGHT / data->all->perp_wall_dist);
	data->all->draw_start = -data->all->line_height / 2 + HEIGHT / 2;
	if (data->all->draw_start < 0)
		data->all->draw_start = 0;
	data->all->draw_end = data->all->line_height / 2 + HEIGHT / 2;
	if (data->all->draw_end >= HEIGHT)
		data->all->draw_end = HEIGHT - 1;
	if (data->all->side == 0)
		data->all->wall_x = data->all->pos_y + data->all->perp_wall_dist
			* data->all->ray_diry;
	else
		data->all->wall_x = data->all->pos_x + data->all->perp_wall_dist
			* data->all->ray_dirx;
	data->all->wall_x -= floor(data->all->wall_x);
	data->all->tex_x = (int)(data->all->wall_x * (double)data->all->tex_width);
	if (data->all->side == 0 && data->all->ray_dirx > 0)
		data->all->tex_x = data->all->tex_width - data->all->tex_x - 1;
	if (data->all->side == 1 && data->all->ray_diry < 0)
		data->all->tex_x = data->all->tex_width - data->all->tex_x - 1;
}

void	draw_color_texture(t_data *data, int x, int tex_num, double step)
{
	double	tex_pos;
	int		tmp;
	int		y;
	int		tex_y;
	int		color;

	y = data->all->draw_start -1;
	tmp = -1;
	tex_pos = (data->all->draw_start - HEIGHT / 2 + data->all->line_height / 2) * step;
	while (++tmp < data->all->draw_start)
		data->all->buf[tmp][x] = data->cord.c_rgb;
	tmp = data->all->draw_end - 1;
	while (++tmp < HEIGHT)
		data->all->buf[tmp][x] = data->cord.f_rgb;
	while (++y <= data->all->draw_end)
	{
		tex_y = (int)tex_pos & (data->all->tex_height - 1);
		tex_pos += step;
		color = data->all->textures[tex_num][data->all->tex_height * tex_y + data->all->tex_x];
		if (data->all->side == 1)
			color = (color >> 1) & 8355711;
		data->all->buf[y][x] = color;
		data->all->re_buf = 1;
	}
}