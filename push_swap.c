/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:42:49 by eablak            #+#    #+#             */
/*   Updated: 2022/12/26 11:47:27 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	ft_get_size(char **av)
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

char	*ft_unify(char **av)
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
		ft_array_control(array[0]);
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

int	*ft_convert_digit(char *str, int size)
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

void	ft_checksame(int *arr, int size)
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

int	main(int ac, char **av)
{
	int		size;
	char	*all_arguments;
	int		*arr;

	(void)ac;
	size = ft_get_size(av) - 1;
	if (size == 0)
		return (1);
	all_arguments = ft_unify(av);
	arr = ft_convert_digit(all_arguments, size);
	ft_checksame(arr, size);
	ft_struct(arr, size);
	free(arr);
}
