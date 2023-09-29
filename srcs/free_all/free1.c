/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:56:20 by fililafrapp       #+#    #+#             */
/*   Updated: 2023/09/29 14:10:56 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	memory_check(void *add, t_data *data)
{
	t_memory	*mem;
	t_memory	*tmp;

	mem = malloc(sizeof(t_memory));
	if (!mem)
		return ;
	mem->add = add;
	mem->next = NULL;
	if (data->d_mem == NULL)
		data->d_mem = mem;
	else
	{
		tmp = data->d_mem;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = mem;
	}
}

void	*ft_malloc(size_t size, t_data *data)
{
	void	*add;

	add = malloc(size);
	if (!add)
		return (NULL);
	memory_check(add, data);
	return (add);
}

void	ft_free_this(void *add, t_data *data)
{
	t_memory	*tmp;
	t_memory	*ex;
	t_memory	*next;

	tmp = data->d_mem;
	ex = NULL;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->add == add)
		{
			tmp->add = NULL;
			free(tmp->add);
			free(tmp);
			if (ex)
				ex->next = next;
			else
				data->d_mem = next;
			return ;
		}
		ex = tmp;
		tmp = tmp->next;
	}
}

void	ft_free_all_garbage(t_data *data)
{
	t_memory	*tmp;
	t_memory	*next;

	tmp = data->d_mem;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->add)
			free(tmp->add);
		free(tmp);
		tmp = next;
	}
}

int	data_free(t_data *data)
{
	mlx_destroy_image(data->all->mlx, data->all->img.img);
	if (data->all->win)
	{
		mlx_clear_window(data->all->mlx, data->all->win);
		mlx_destroy_window(data->all->mlx, data->all->win);
	}
	if (data->all->mlx)
	{
		mlx_destroy_display(data->all->mlx);
		free(data->all->mlx);
	}
	return (0);
}
