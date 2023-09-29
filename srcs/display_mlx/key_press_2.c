/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:52:40 by kgezgin           #+#    #+#             */
/*   Updated: 2023/09/29 15:31:36 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	up(t_data **data)
{
	if (((*data)->all->pos_x + (*data)->all->dir_x
			* (*data)->all->move_speed) > 0
		&& '1' != (*data)->map_ray[((int)((*data)->all->pos_x
				+ ((*data)->all->dir_x
					* (*data)->all->move_speed)))]
						[(int)((*data)->all->pos_y)])
		(*data)->all->pos_x += (*data)->all->dir_x
			* (*data)->all->move_speed;
	if (((*data)->all->pos_y + (*data)->all->dir_y
			* (*data)->all->move_speed) > 0
		&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x)]
					[((int)((*data)->all->pos_y
					+ ((*data)->all->dir_y * (*data)->all->move_speed)))])
		(*data)->all->pos_y += (*data)->all->dir_y
			* (*data)->all->move_speed;
}

void	down(t_data **data)
{
	if (((*data)->all->pos_x - (*data)->all->dir_x
			* (*data)->all->move_speed) > 0
		&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x
			- (*data)->all->dir_x
			* (*data)->all->move_speed)][(int)((*data)->all->pos_y)])
		(*data)->all->pos_x -= (*data)->all->dir_x
			* (*data)->all->move_speed;
	if (((*data)->all->pos_y - (*data)->all->dir_y
			* (*data)->all->move_speed) > 0
		&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x)]
					[(int)((*data)->all->pos_y
					- (*data)->all->dir_y * (*data)->all->move_speed)])
		(*data)->all->pos_y -= (*data)->all->dir_y
			* (*data)->all->move_speed;
}

void	left(t_data **data)
{
	if (((*data)->all->pos_x - (*data)->all->dir_y
			* (*data)->all->move_speed) > 0
		&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x
			- (*data)->all->dir_y
			* (*data)->all->move_speed)][(int)((*data)->all->pos_y)])
		(*data)->all->pos_x -= (*data)->all->dir_y
			* (*data)->all->move_speed;
	if (((*data)->all->pos_y + (*data)->all->dir_x
			* (*data)->all->move_speed) > 0
		&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x)]
					[(int)((*data)->all->pos_y
					+ (*data)->all->dir_x * (*data)->all->move_speed)])
		(*data)->all->pos_y += (*data)->all->dir_x
			* (*data)->all->move_speed;
}

void	right(t_data **data)
{
	if (((*data)->all->pos_x + (*data)->all->dir_y
			* (*data)->all->move_speed) > 0
		&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x
			+ (*data)->all->dir_y
			* (*data)->all->move_speed)][(int)((*data)->all->pos_y)])
		(*data)->all->pos_x += (*data)->all->dir_y
			* (*data)->all->move_speed;
	if (((*data)->all->pos_y - (*data)->all->dir_x
			* (*data)->all->move_speed) > 0
		&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x)]
					[(int)((*data)->all->pos_y
					- (*data)->all->dir_x * (*data)->all->move_speed)])
		(*data)->all->pos_y -= (*data)->all->dir_x
			* (*data)->all->move_speed;
}
