/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_part2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:05:25 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 16:12:19 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ra(t_struct **a)
{
	t_struct	*begin;
	t_struct	*new_begin;
	t_struct	*new_keep;
	t_struct	*x;

	x = malloc(sizeof(t_struct));
	begin = *a;
	new_begin = begin->next;
	x->data = begin->data;
	x->next = NULL;
	begin->next = NULL;
	new_keep = new_begin;
	while (new_begin->next != NULL)
		new_begin = new_begin->next;
	new_begin->next = x;
	free(begin);
	(*a) = new_keep;
	write(1, "ra\n", 3);
}

void	rb(t_struct **b)
{
	t_struct	*begin;
	t_struct	*new_begin;
	t_struct	*new_keep;
	t_struct	*x;

	x = malloc(sizeof(t_struct));
	begin = *b;
	new_begin = begin->next;
	x->data = begin->data;
	x->next = NULL;
	begin->next = NULL;
	free(begin);
	new_keep = new_begin;
	while (new_begin->next)
		new_begin = new_begin->next;
	new_begin->next = x;
	(*b) = new_keep;
	write(1, "rb\n", 3);
}

t_struct	*sa(t_struct **a)
{
	t_struct	*begin;
	int			temp;

	begin = (*a);
	temp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = temp;
	write(1, "sa\n", 3);
	return (begin);
}

void	pa(t_holder *holder)
{
	t_struct	*a;
	t_struct	*b;
	t_struct	*keep_b;
	t_struct	*nnew;

	nnew = malloc(sizeof(t_struct));
	a = holder->a;
	b = (t_struct *)holder->b;
	if (b == NULL)
		return ;
	keep_b = b->next;
	nnew->data = b->data;
	b->next = NULL;
	free(b);
	holder->b = keep_b;
	nnew->next = a;
	holder->a = nnew;
	holder->size_a++;
	holder->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_holder *holder)
{
	t_struct	*keep_a;
	t_struct	*nnew;

	nnew = malloc(sizeof(t_struct));
	if (holder->a == NULL)
		return ;
	keep_a = holder->a->next;
	nnew->data = holder->a->data;
	nnew->next = NULL;
	free(holder->a);
	holder->a = keep_a;
	if (holder->b == NULL)
		holder->b = nnew;
	else
	{
		nnew->next = holder->b;
		holder->b = nnew;
	}
	holder->size_a--;
	holder->size_b++;
	write(1, "pb\n", 3);
}
