/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:30:28 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/27 14:39:36 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	key_press(int key, t_data **data)
{
	if (key == 119)
	{
		if (((*data)->all->pos_x + (*data)->all->dir_x * (*data)->all->move_speed) > 0
			&& '1' != (*data)->map_ray[((int)((*data)->all->pos_x + ((*data)->all->dir_x
						* (*data)->all->move_speed)))][(int)((*data)->all->pos_y)])
			(*data)->all->pos_x += (*data)->all->dir_x * (*data)->all->move_speed;
		if (((*data)->all->pos_y + (*data)->all->dir_y * (*data)->all->move_speed) > 0
			&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x)][((int)((*data)->all->pos_y
				+ ((*data)->all->dir_y * (*data)->all->move_speed)))])
			(*data)->all->pos_y += (*data)->all->dir_y * (*data)->all->move_speed;
	}
	if (key == 115)
	{
		if (((*data)->all->pos_x - (*data)->all->dir_x * (*data)->all->move_speed) > 0
			&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x
				- (*data)->all->dir_x * (*data)->all->move_speed)][(int)((*data)->all->pos_y)])
			(*data)->all->pos_x -= (*data)->all->dir_x * (*data)->all->move_speed;
		if (((*data)->all->pos_y - (*data)->all->dir_y * (*data)->all->move_speed) > 0
			&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x)][(int)((*data)->all->pos_y
				- (*data)->all->dir_y * (*data)->all->move_speed)])
			(*data)->all->pos_y -= (*data)->all->dir_y * (*data)->all->move_speed;
	}
	if (key == 65307)
		mlx_loop_end((*data)->all->mlx);
	return (key_press_suite(key, data));
}

int	key_press_suite(int key, t_data **data)
{
	if (key == 100)
	{
		if (((*data)->all->pos_x + (*data)->all->dir_y * (*data)->all->move_speed) > 0
			&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x + (*data)->all->dir_y
				* (*data)->all->move_speed)][(int)((*data)->all->pos_y)])
			(*data)->all->pos_x += (*data)->all->dir_y * (*data)->all->move_speed;
		if (((*data)->all->pos_y - (*data)->all->dir_x * (*data)->all->move_speed) > 0
			&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x)][(int)((*data)->all->pos_y
				- (*data)->all->dir_x * (*data)->all->move_speed)])
			(*data)->all->pos_y -= (*data)->all->dir_x * (*data)->all->move_speed;
	}
	if (key == 97)
	{
		if (((*data)->all->pos_x - (*data)->all->dir_y * (*data)->all->move_speed) > 0
			&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x
				- (*data)->all->dir_y * (*data)->all->move_speed)][(int)((*data)->all->pos_y)])
			(*data)->all->pos_x -= (*data)->all->dir_y * (*data)->all->move_speed;
		if (((*data)->all->pos_y + (*data)->all->dir_x * (*data)->all->move_speed) > 0
			&& '1' != (*data)->map_ray[(int)((*data)->all->pos_x)][(int)((*data)->all->pos_y
				+ (*data)->all->dir_x * (*data)->all->move_speed)])
			(*data)->all->pos_y += (*data)->all->dir_x * (*data)->all->move_speed;
	}
	return (key_press_move_camera_right(key, data));
}

int	key_press_move_camera_right(int key, t_data **data)
{
	double	tmp;

	if (key == 65363)
	{
		tmp = (*data)->all->dir_x;
		(*data)->all->dir_x = (*data)->all->dir_x * cos(-(*data)->all->rot_speed) - (*data)->all->dir_y
			* sin(-(*data)->all->rot_speed);
		(*data)->all->dir_y = tmp * sin(-(*data)->all->rot_speed) + (*data)->all->dir_y
			* cos(-(*data)->all->rot_speed);
		tmp = (*data)->all->plane_x;
		(*data)->all->plane_x = (*data)->all->plane_x * cos(-(*data)->all->rot_speed) - (*data)->all->plane_y
			* sin(-(*data)->all->rot_speed);
		(*data)->all->plane_y = tmp * sin(-(*data)->all->rot_speed) + (*data)->all->plane_y
			* cos(-(*data)->all->rot_speed);
	}
	return (key_press_move_camera_left(key, data));
}

int	key_press_move_camera_left(int key, t_data **data)
{
	double	tmp;

	if (key == 65361)
	{
		tmp = (*data)->all->dir_x;
		(*data)->all->dir_x = (*data)->all->dir_x * cos((*data)->all->rot_speed) - (*data)->all->dir_y
			* sin((*data)->all->rot_speed);
		(*data)->all->dir_y = tmp * sin((*data)->all->rot_speed) + (*data)->all->dir_y
			* cos((*data)->all->rot_speed);
		tmp = (*data)->all->plane_x;
		(*data)->all->plane_x = (*data)->all->plane_x * cos((*data)->all->rot_speed) - (*data)->all->plane_y
			* sin((*data)->all->rot_speed);
		(*data)->all->plane_y = tmp * sin((*data)->all->rot_speed) + (*data)->all->plane_y
			* cos((*data)->all->rot_speed);
	}
	return (0);
}