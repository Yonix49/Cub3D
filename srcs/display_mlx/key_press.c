/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:30:28 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/29 15:31:18 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	key_press(int key, t_data **data)
{
	if (key == 119)
		up(data);
	if (key == 115)
		down(data);
	if (key == 65307)
		mlx_loop_end((*data)->all->mlx);
	return (key_press_suite(key, data));
}

int	key_press_suite(int key, t_data **data)
{
	if (key == 100)
		right(data);
	if (key == 97)
		left(data);
	return (key_press_move_camera_right(key, data));
}

int	key_press_move_camera_right(int key, t_data **data)
{
	double	tmp;

	if (key == 65363)
	{
		tmp = (*data)->all->dir_x;
		(*data)->all->dir_x = (*data)->all->dir_x
			* cos(-(*data)->all->rot_speed) - (*data)->all->dir_y
			* sin(-(*data)->all->rot_speed);
		(*data)->all->dir_y = tmp * sin(-(*data)->all->rot_speed)
			+ (*data)->all->dir_y * cos(-(*data)->all->rot_speed);
		tmp = (*data)->all->plane_x;
		(*data)->all->plane_x = (*data)->all->plane_x
			* cos(-(*data)->all->rot_speed) - (*data)->all->plane_y
			* sin(-(*data)->all->rot_speed);
		(*data)->all->plane_y = tmp * sin(-(*data)->all->rot_speed)
			+ (*data)->all->plane_y * cos(-(*data)->all->rot_speed);
	}
	return (key_press_move_camera_left(key, data));
}

int	key_press_move_camera_left(int key, t_data **data)
{
	double	tmp;

	if (key == 65361)
	{
		tmp = (*data)->all->dir_x;
		(*data)->all->dir_x = (*data)->all->dir_x * cos((*data)->all->rot_speed)
			- (*data)->all->dir_y * sin((*data)->all->rot_speed);
		(*data)->all->dir_y = tmp * sin((*data)->all->rot_speed)
			+ (*data)->all->dir_y * cos((*data)->all->rot_speed);
		tmp = (*data)->all->plane_x;
		(*data)->all->plane_x = (*data)->all->plane_x
			* cos((*data)->all->rot_speed) - (*data)->all->plane_y
			* sin((*data)->all->rot_speed);
		(*data)->all->plane_y = tmp * sin((*data)->all->rot_speed)
			+ (*data)->all->plane_y * cos((*data)->all->rot_speed);
	}
	return (0);
}
