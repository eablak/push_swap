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

t_struct	*ft_cr_struct(int i)
{
	t_struct	*new_struct;

	new_struct = malloc(sizeof(t_struct));
	if (!new_struct)
		return (0);
	new_struct->data = i;
	new_struct->next = NULL;
	return (new_struct);
}

void	ft_struct_addback(t_struct **strct, t_struct *new)
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

void	ft_struct(int *arr, int size)
{
	t_struct	*first_struct;
	t_struct	*a_struct;
	t_struct	*bas;
	int			i;

	first_struct = malloc(sizeof(t_struct));
	if (!first_struct)
		return ;
	first_struct->data = arr[0];
	first_struct->next = NULL;
	bas = first_struct;
	i = 1;
	while (i < size)
	{
		a_struct = ft_cr_struct(arr[i]);
		ft_struct_addback(&first_struct, a_struct);
		i++;
	}
	ft_forsize(size, &bas);
}
