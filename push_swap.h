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

typedef struct sorted_struct
{
	int				first;
	int				len;
}					sorted_struct;

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
	sorted_struct		sorted;
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

void				build_struct(int *arr, int size);
t_struct			*create_struct(int i);
void				ra(t_struct **a);
void				rb(t_struct **b);
void				rra(t_struct **a);
void				rrb(t_struct **b);
t_struct			*sa(t_struct **a);

void				process_by_size(int size, t_struct **my_struct);
void				binary_sorting(t_struct **a);
void				triple_sorting(t_struct **a, int flag);
void				triple_utils(t_struct **a);
void				quarted_quintette(t_struct **a, t_struct *b, int size);
void				big_sort(t_struct **a, t_struct *b, int size);
void				find_min_data(t_holder *holder);
int					*bubble_sort(int *numeros, int size);
void				placing_values(t_holder *holder, sorted_struct sorted, int size);

void				pa(t_holder *holder);
void				pb(t_holder *holder);
int					*cr_copy_arr(t_struct **a, int size);

int					up_b(t_holder *holder, t_struct *use_b, int data);
void				replacement(t_holder *holder, int *arr);
int					locationA(t_holder *holder, int *arr);
int					ft_check_max(t_holder *holder, int data);
int					ft_check_inter(t_holder *holder, int data, int *arr);
void				run_as(int data, t_holder *holder);
void				moveUpB(t_holder *holder, int data);
t_struct			*b_with_rb(t_struct *b, int size);
t_struct			*b_with_rrb(t_struct *b, int size);
void				locateA(t_holder *holder, int *arr);
void				location_inter(t_holder *holder);
int					find_in_arr(int *arr, int data, t_holder *holder);
int					check_max(t_holder *holder);
int					check_min(t_holder *holder);
int					up_min_a(t_holder *holder);
void				moveUpA(t_holder *holder);
void				ft_make_a(t_holder *holder, int count);
void				locateInter(t_holder *holder, int *arr);
int					is_descending(t_struct **a, int size);
int					correct_count(t_holder *holder, int *arr, int data);
void				ft_free(t_struct **strct);
void				rrb_utils(t_struct_rra *s_rrb, t_struct **b);
void				find_sorted_max(t_strct_bigsort *big_strct);
void				sorted_stayA(t_holder *holder, int i);
sorted_struct			find_sorted(t_struct **a);
void				ft_finish(t_holder *holder, int count);
void				ft_array_control(char *all_array);

void print_result(t_struct *holder_a);
#endif