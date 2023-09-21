/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:56:20 by fililafrapp       #+#    #+#             */
/*   Updated: 2023/09/21 15:40:54 by mhajji-b         ###   ########.fr       */
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

	tmp =  data->d_mem;
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
