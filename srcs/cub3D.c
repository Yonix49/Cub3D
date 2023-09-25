/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/25 15:23:00 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "string.h"

void	*realloc_map(void *ptr, size_t ptrsize, size_t newsize, t_data *data)
{
	void	*newptr;

	if (ptr == NULL)
		return (ft_calloc(newsize, 1, data));
	if (newsize == 0)
		return (NULL);
	if (newsize <= ptrsize)
		return (ptr);
	newptr = ft_calloc(newsize, 1, data);
	if (!newptr)
		return (NULL);
	ft_memcpy(newptr, ptr, ptrsize);
	// free(ptr);
	return (newptr);
}

int	init_data(t_data *data)
{
	ft_memset((data), 0, sizeof(t_data));
	// data->map_compass = NULL;
	// data->map = NULL;
	return (0);
}

// int	init_window(t_data_box *d)
// {
// 	int	x;
// 	int	y;

// 	x = d->ma->x * 64;
// 	y = d->ma->y * 64;
// 	d->m = malloc(sizeof(t_mlx));
// 	if (!d->m)
// 		return (0);
// 	d->m->m = mlx_init();
// 	if (!d->m->m)
// 		exit(EXIT_FAILURE);
// 	d->m->win = mlx_new_window(d->m->m, x, y, "So_long");
// 	if (!d->m->win)
// 		return (free(d->m->m), 0);
// 	if (!set_images(d))
// 		return (ft_printf("Error\nImages Not OK\n"), 0);
// 	display_map(d);
// 	mlx_hook(d->m->win, 17, 0, mlx_loop_end, d->m->m);
// 	mlx_key_hook(d->m->win, moves, d);
// 	mlx_loop(d->m->m);
// 	return (0);
// }
// int	init_window(t_data_box *d)
// {

// 	x = d->ma->x * 64;
// 	y = d->ma->y * 64;
// 	d->m = malloc(sizeof(t_mlx));
// 	d->m->m = mlx_init();
// 	if (!d->m->m)
// 		exit(EXIT_FAILURE);
// 	d->m->win = mlx_new_window(d->m->m, x, y, "So_long");
// 	if (!d->m->win)
// 		return (free(d->m->m), 0);
// 	if (!set_images(d))
// 		return (ft_printf("Error\nImages Not OK\n"), 0);
// 	display_map(d);
// 	mlx_hook(d->m->win, 17, 0, mlx_loop_end, d->m->m);
// 	mlx_key_hook(d->m->win, moves, d);
// 	mlx_loop(d->m->m);
// 	return (0);
// }
int	main(int argc, char **argv, char **env)
{
	t_data	data;

	init_data(&data);
	if ((verif_namearg(argc, argv)) != 0 || verif_open(argv) != 0
		|| env[0] == NULL)
		return (ft_free_all_garbage(&data), 3);
	if (get_different_maps(&data, argv) != 0)
		return (ft_free_all_garbage(&data), 1);
	if (check_all_compass(&data) != 0)
		return (ft_free_all_garbage(&data), 2);
	if (parsing_map_wall(&data) != 0)
		return (ft_free_all_garbage(&data), 6);
	if (start_mlx(&data) != 0)
		return (ft_free_all_garbage(&data), 7);
	return (ft_free_all_garbage(&data), 0);
	
}
