/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:42:49 by eablak            #+#    #+#             */
/*   Updated: 2023/09/22 12:49:44 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	get_size(char **av)
{
	int		i;
	int		size;
	char	**array;
	int		j;

	i = 0;
	size = 0;
	while (av[i])
	{
		array = ft_split(av[i], ' ');
		j = 0;
		while (array[j])
		{
			free(array[j]);
			j++;
			size++;
		}
		free(array);
		i++;
	}
	return (size);
}

char	*unify(char **av)
{
	int		i;
	char	*all_array;
	char	**array;
	int		j;

	i = 1;
	all_array = NULL;
	while (av[i])
	{
		array = ft_split(av[i], ' ');
		array_control(array[0]);
		j = 0;
		while (array[j])
		{
			all_array = ft_strjoin(all_array, array[j]);
			all_array = ft_strjoin(all_array, " ");
			free(array[j]);
			j++;
		}
		free(array);
		i++;
	}
	return (all_array);
}

int	*convert_digit(char *str, int size)
{
	int		i;
	char	**array;
	int		*int_array;
	int		j;

	i = 0;
	int_array = malloc(sizeof(int) * size);
	while (str[i])
	{
		array = ft_split(str, ' ');
		j = 0;
		while (array[j])
		{
			int_array[j] = ft_atoi(array[j]);
			free(array[j]);
			j++;
		}
		free(array);
		i++;
	}
	free(str);
	return (int_array);
}

void	check_same(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_nan(char *all_arguments){
	int i;

	i =0;
	while(all_arguments[i]){
		if (all_arguments[i] == '-' && (all_arguments[i+1] == '\0' || all_arguments[i+1] == ' '))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (!(all_arguments[i] >= 48 && all_arguments[i] <= 57) && all_arguments[i] != '-' && all_arguments[i] != ' '){
			write(2, "Error\n", 6);
			free(all_arguments);
			exit(1);
		}
		i++;
	}
}

void check_sorted(int *arr, int size){
	int i = 0;
	int j = 0;
	while (i < size)
	{
		j = i;
		int nbr = arr[i];
		while(j < size){
			if (nbr > arr[j])
				return ;
			j++;
		}
		i++;
	}
	exit(1);
}

int	main(int ac, char **av)
{
	int		size;
	char	*all_arguments;
	int		*arr;

	(void)ac;
	size = get_size(av) - 1;
	if (size == 0)
		return (1);
	all_arguments = unify(av);
	check_nan(all_arguments);
	arr = convert_digit(all_arguments, size);
	check_sorted(arr, size);
	check_same(arr, size);
	build_struct(arr, size);
	free(arr);
}
