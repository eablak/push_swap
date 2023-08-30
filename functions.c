/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:05:21 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 16:18:30 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	rra_utils(t_struct_rra *s_rra, t_struct **a)
{
	s_rra->x->next = s_rra->dont_lose_begin;
	s_rra->last_free = s_rra->x;
	while (s_rra->j < s_rra->i)
	{
		s_rra->last_free = s_rra->last_free->next;
		s_rra->j++;
	}
	s_rra->last_free->next = NULL;
	(*a) = s_rra->x;
	write(1, "rra\n", 4);
	free(s_rra);
}

void	rra(t_struct **a)
{
	t_struct_rra	*s_rra;

	s_rra = malloc(sizeof(t_struct_rra));
	s_rra->x = malloc(sizeof(t_struct));
	s_rra->i = 0;
	s_rra->j = 0;
	s_rra->begin = (*a);
	s_rra->dont_lose_begin = s_rra->begin;
	while (s_rra->begin->next)
	{
		s_rra->begin = s_rra->begin->next;
		s_rra->i++;
	}
	s_rra->x->data = s_rra->begin->data;
	s_rra->x->next = NULL;
	free(s_rra->begin);
	rra_utils(s_rra, a);
}

void	rrb_utils(t_struct_rra *s_rrb, t_struct **b)
{
	s_rrb->x->next = s_rrb->dont_lose_begin;
	s_rrb->last_free = s_rrb->x;
	while (s_rrb->j < s_rrb->i)
	{
		s_rrb->last_free = s_rrb->last_free->next;
		s_rrb->j++;
	}
	s_rrb->last_free->next = NULL;
	(*b) = s_rrb->x;
	write(1, "rrb\n", 4);
	free(s_rrb);
}

void	rrb(t_struct **b)
{
	t_struct_rra	*s_rrb;

	s_rrb = malloc(sizeof(t_struct_rra));
	if ((*b)->next == NULL)
		return ;
	s_rrb->x = malloc(sizeof(t_struct));
	s_rrb->i = 0;
	s_rrb->j = 0;
	s_rrb->begin = (*b);
	s_rrb->dont_lose_begin = s_rrb->begin;
	while (s_rrb->begin->next)
	{
		s_rrb->begin = s_rrb->begin->next;
		s_rrb->i++;
	}
	s_rrb->x->data = s_rrb->begin->data;
	s_rrb->x->next = NULL;
	free(s_rrb->begin);
	rrb_utils(s_rrb, b);
}

int	*bubble_sort(int *numeros, int size)
{
	int	i;
	int	tmp;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (numeros[i] > numeros[i + 1])
			{
				tmp = numeros[i];
				numeros[i] = numeros[i + 1];
				numeros[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
	return (numeros);
}
