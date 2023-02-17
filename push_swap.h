/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:48:20 by eablak            #+#    #+#             */
/*   Updated: 2022/12/21 14:09:01 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_struct
{
	int				data;
	struct t_struct	*next;
}					t_struct;

typedef struct t_struct2
{
	int				first;
	int				len;
}					t_struct2;

typedef struct t_struct3
{
	t_struct		*begin;
	t_struct		*last_free;
	t_struct		*dont_lose_begin;
	t_struct		*x;
	int				i;
	int				j;
}					t_struct_rra;

typedef struct t_struct4
{
	t_struct		*begin;
	t_struct2		sorted;
	t_struct		*start;
	t_struct		*end;
	t_struct		*temp;
	t_struct		*temp2;
	int				len;
	int				real_len;
}					t_strct_bigsort;

typedef struct s_holder
{
	t_struct		*a;
	t_struct		*b;
	int				size_a;
	int				size_b;
}					t_holder;

void				ft_struct(int *arr, int size);
t_struct			*ft_cr_struct(int i);
void				ra(t_struct **a);
void				rb(t_struct **b);
void				rra(t_struct **a);
void				rrb(t_struct **b);
t_struct			*sa(t_struct **a);

void				ft_forsize(int size, t_struct **my_struct);
void				ft_fortwo(t_struct **a);
void				ft_forthree(t_struct **a, int flag);
void				ft_forthree2(t_struct **a);
void				ft_fourfive(t_struct **a, t_struct *b, int size);
void				ft_forall(t_struct **a, t_struct *b, int size);
void				find_min_data(t_holder *holder);
int					*bubble_sort(int *numeros, int size);
void				sorted_stay_a(t_holder *holder, t_struct2 sorted, int size);

void				pa(t_holder *holder);
void				pb(t_holder *holder);
int					*cr_copy_arr(t_struct **a, int size);

int					up_b(t_holder *holder, t_struct *use_b, int data);
void				find_min_step(t_holder *holder, int *arr);
int					location_a(t_holder *holder, int *arr);
int					ft_check_max(t_holder *holder, int data);
int					ft_check_inter(t_holder *holder, int data, int *arr);
void				ft_run_as(int data, t_holder *holder);
void				make_numb_up_b(t_holder *holder, int data);
t_struct			*b_with_rb(t_struct *b, int size);
t_struct			*b_with_rrb(t_struct *b, int size);
void				locate_a(t_holder *holder, int *arr);
void				location_inter(t_holder *holder);
int					find_in_arr(int *arr, int data, t_holder *holder);
int					check_max(t_holder *holder);
int					check_min(t_holder *holder);
int					up_min_a(t_holder *holder);
void				make_up_a(t_holder *holder);
void				ft_make_a(t_holder *holder, int count);
void				locate_inter(t_holder *holder, int *arr);
int					is_descending(t_struct **a, int size);
int					ft_correct_count(t_holder *holder, int *arr, int data);
void				ft_free(t_struct **strct);
void				rrb_2(t_struct_rra *s_rrb, t_struct **b);
void				find_sort_2(t_strct_bigsort *st_b_s);
void				sorted_stay_a2(t_holder *holder, int i, int len_a);
t_struct2			find_sort(t_struct **a);
void				ft_finish(t_holder *holder, int count);
void				ft_array_control(char *all_array);
#endif