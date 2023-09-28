/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:45:32 by kgezgin           #+#    #+#             */
/*   Updated: 2023/09/28 14:28:27 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	init_dda(t_data *data, int *step_x, int *step_y)
{
	data->all->delta_distx = fabs(1 / data->all->ray_dirx);
	data->all->delta_disty = fabs(1 / data->all->ray_diry);
	if (data->all->ray_dirx < 0)
	{
		*step_x = -1;
		data->all->side_distx = (data->all->pos_x - data->all->map_x)
			* data->all->delta_distx;
	}
	else
	{
		*step_x = 1;
		data->all->side_distx = (data->all->map_x + 1.0 - data->all->pos_x)
			* data->all->delta_distx;
	}
	return (init_dda_2(data, step_y));
}

void	init_dda_2(t_data *data, int *step_y)
{
	if (data->all->ray_diry < 0)
	{
		*step_y = -1;
		data->all->side_disty = (data->all->pos_y - data->all->map_y)
			* data->all->delta_disty;
	}
	else
	{
		*step_y = 1;
		data->all->side_disty = (data->all->map_y + 1.0 - data->all->pos_y)
			* data->all->delta_disty;
	}
}

void	dda(t_data *data, int step_x, int step_y)
{
	while (data->all->map_x >= 0 && data->all->map_y >= 0)
	{
		if (data->all->side_distx < data->all->side_disty)
		{
			data->all->side_distx += data->all->delta_distx;
			data->all->map_x += step_x;
			data->all->side = 0;
		}
		else
		{
			data->all->side_disty += data->all->delta_disty;
			data->all->map_y += step_y;
			data->all->side = 1;
		}
		if (data->map_ray[data->all->map_x][data->all->map_y]
			&& data->map_ray[data->all->map_x][data->all->map_y] > '0'
			&& data->map_ray[data->all->map_x][data->all->map_y] != '*')
			break ;
	}
}

void	calcul(t_data **data)
{
	int	step_x;
	int	step_y;

	(*data)->x = -1;
	while (++(*data)->x < WIDTH)
	{
		(*data)->all->map_x = (int)(*data)->all->pos_x;
		(*data)->all->map_y = (int)(*data)->all->pos_y;
		(*data)->all->ray_dirx = (*data)->all->dir_x + ((*data)->all->plane_x
				* ((double)(2 * (*data)->x / (double)WIDTH - 1)));
		(*data)->all->ray_diry = (*data)->all->dir_y + ((*data)->all->plane_y
				* ((double)(2 * (*data)->x / (double)WIDTH - 1)));
		init_dda((*data), &step_x, &step_y);
		dda((*data), step_x, step_y);
		draw_utils((*data), step_x, step_y);
		draw_color_texture((*data), (*data)->x, get_num_tex((*data)),
			(double)(1.0 * (*data)->all->tex_height
				/ (*data)->all->line_height));
	}
}
