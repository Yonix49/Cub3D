/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:46:17 by kgezgin           #+#    #+#             */
/*   Updated: 2023/09/28 14:06:46 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

int	set_images(t_data *data)
{
	t_imag	img;

	if (!malloc_textures(data))
		return (0);
	if (!set_main_img(data))
		return (0);
	if (!load_image(data, data->all->textures[0], data->cord.path_texture_no,
			&img))
		return (0);
	if (!load_image(data, data->all->textures[1], data->cord.path_texture_so,
			&img))
		return (0);
	if (!load_image(data, data->all->textures[2], data->cord.path_texture_we,
			&img))
		return (0);
	if (!load_image(data, data->all->textures[3], data->cord.path_texture_ea,
			&img))
		return (0);
	return (1);
}

int	set_main_img(t_data *data)
{
	data->all->img.img = mlx_new_image(data->all->mlx, WIDTH, HEIGHT);
	if (!data->all->img.img)
		return (ft_putstr_fd(2, "Error\nFailed to create image\n"), 0);
	data->all->img.data = (int *)mlx_get_data_addr(data->all->img.img,
			&data->all->img.bpp, &data->all->img.size_l,
			&data->all->img.endian);
	return (1);
}

int	load_image(t_data *data, int *texture, char *path, t_imag *img)
{
	int	x;
	int	y;

	y = -1;
	img->img = mlx_xpm_file_to_image(data->all->mlx, path, &img->img_width,
			&img->img_height);
	if (!img->img)
		return (0);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l,
			&img->endian);
	if (!img->data)
	{
		mlx_destroy_image(data->all->mlx, img->img);
		return (0);
	}
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(data->all->mlx, img->img);
	return (1);
}
