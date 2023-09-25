/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:45:32 by kgezgin           #+#    #+#             */
/*   Updated: 2023/09/25 18:11:48 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	init_for_dda(t_data *data, int *step_x, int *step_y)
{
	data->all->delta_distx = fabs(1 / data->all->ray_dirx);
    data->all->delta_disty = fabs(1 / data->all->ray_diry);
    if (data->all->ray_dirx < 0)
    {
        *step_x = -1;
       data->all->side_distx = (data->all->pos_x - data->all->map_x) *data->all->delta_distx;
    }
    else
    {
        *step_x = 1;
        data->all->side_distx = (data->all->map_x + 1.0 - data->all->pos_x) * data->all->delta_distx;
    }
    // return (init_calc2(info, step_y));    continuer ici !!!! 
}

void	calcul(t_data *data)
{
	int	x;
	int step_x;
    int step_y;

	x = -1;
	while (++x < WIDTH)
    {
		data->all->map_x = (int)data->all->pos_x;
		data->all->map_y = (int)data->all->pos_y;
		data->all->ray_dirx = data->all->dir_x + (data->all->plane_x * ((double)(2 * x / (double)WIDTH - 1)));
        data->all->ray_diry = data->all->dir_y + (data->all->plane_y * ((double)(2 * x / (double)WIDTH - 1)));
		init_for_dda(data, &step_x, &step_y);
	}
}
