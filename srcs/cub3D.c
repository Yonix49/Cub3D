/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/29 14:12:06 by kgezgin          ###   ########.fr       */
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
	return (newptr);
}

int	init_data(t_data *data)
{
	ft_memset((data), 0, sizeof(t_data));
	return (0);
}

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
	data.f_rgb = 65536 * ft_atoi(data.ff_rgb[0]) + 256 * ft_atoi(data.ff_rgb[1])
		+ ft_atoi(data.ff_rgb[2]);
	data.c_rgb = 65536 * ft_atoi(data.cc_rgb[0]) + 256 * ft_atoi(data.cc_rgb[1])
		+ ft_atoi(data.cc_rgb[2]);
	if (start_mlx(&data) != 0)
		return (ft_free_all_garbage(&data), 7);
	return (ft_free_all_garbage(&data), 0);
}
