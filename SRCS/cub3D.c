/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:29 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/09/22 14:48:53 by mhajji-b         ###   ########.fr       */
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
	data->cord.path_texture_no = NULL;
	data->cord.path_texture_so = NULL;
	data->cord.path_texture_we = NULL;
	data->cord.path_texture_ea = NULL;
	data->cord.f_rgb = 0;
	data->cord.c_rgb = 0;
	// data->map_compass = NULL;
	// data->map = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if ((verif_namearg(argc, argv)) != 0 || verif_open(argv) != 0)
	{
		ft_free_all_garbage(&data);
		return (3);
	}
	if (get_different_maps(&data, argv) != 0)
	{
		ft_free_all_garbage(&data);
		return (1);
	}
	if (parsing_compass(&data) != 0)
	{
		ft_free_all_garbage(&data);
		return (2);
	}
	if (parsing_map_wall(&data) != 0)
	{
		ft_free_all_garbage(&data);
		return (6);
	}
	ft_free_all_garbage(&data);
	return (0);
}
// leak pour mauvaise map void space