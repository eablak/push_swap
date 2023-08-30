/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:45:21 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 16:41:34 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*create_struct(int i)
{
	t_struct	*new_struct;

	new_struct = malloc(sizeof(t_struct));
	if (!new_struct)
		return (0);
	new_struct->data = i;
	new_struct->next = NULL;
	return (new_struct);
}

void	struct_addback(t_struct **strct, t_struct *new)
{
	if (*strct == NULL || new == NULL)
	{
		*strct = new;
		return ;
	}
	while ((*strct)->next != NULL)
	{
		(*strct) = (*strct)->next;
	}
	(*strct)->next = new;
}

void	ft_free(t_struct **strct)
{
	t_struct	*tmp;
	int			i;

	i = 0;
	while ((*strct))
	{
		tmp = (*strct)->next;
		free((*strct));
		(*strct) = tmp;
		i++;
	}
}

void	build_struct(int *arr, int size)
{
	t_struct	*main_struct;
	t_struct	*created_struct;
	t_struct	*copy_struct;
	int			i;

	main_struct = malloc(sizeof(t_struct));
	if (!main_struct)
		return ;
	main_struct->data = arr[0];
	main_struct->next = NULL;
	copy_struct = main_struct;
	i = 1;
	while (i < size)
	{
		created_struct = create_struct(arr[i]);
		struct_addback(&main_struct, created_struct);
		i++;
	}
	process_by_size(size, &copy_struct);
}
