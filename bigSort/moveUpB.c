/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_part3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:21:59 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 16:34:29 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_struct	*b_with_rb(t_struct *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		rb(&b);
		i++;
	}
	return (b);
}

t_struct	*b_with_rrb(t_struct *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		rrb(&b);
		i++;
	}
	return (b);
}

int	moveUpB_utils(t_holder *holder, int data, int *size)
{
	t_struct	*keep_b;
	int			rb;

	rb = 0;
	keep_b = holder->b;
	while (holder->b)
	{
		if (holder->b->data == data && *size <= holder->size_b / 2)
		{
			rb = 1;
			break ;
		}
		else if (holder->b->data == data && *size > holder->size_b / 2)
		{
			*size = holder->size_b - *size;
			rb = 2;
			break ;
		}
		holder->b = holder->b->next;
		*size += 1;
	}
	holder->b = keep_b;
	return (rb);
}

void	moveUpB(t_holder *holder, int data)
{
	t_struct	*keep_a;
	int			size;
	int			rb;

	keep_a = holder->a;
	size = 0;
	rb = moveUpB_utils(holder, data, &size);
	if (rb == 1)
		holder->b = b_with_rb(holder->b, size);
	else if (rb == 2)
		holder->b = b_with_rrb(holder->b, size);
}

void	run_as(int data, t_holder *holder)
{
	t_struct	*keep_a;
	t_struct	*keep_b;

	keep_a = holder->a;
	keep_b = holder->b;
	moveUpB(holder, data);
}
