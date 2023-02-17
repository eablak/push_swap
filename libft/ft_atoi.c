/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:40:20 by eablak            #+#    #+#             */
/*   Updated: 2022/12/26 11:47:46 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_control(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

long	ft_func(const char *str, long sayi, int neg, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		sayi = sayi * 10 + (str[i] - 48);
		if (sayi * neg < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		else if (sayi * neg > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (sayi);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	sayi;

	neg = 1;
	sayi = 0;
	i = 0;
	if (str[0] == '-')
	{
		neg = -1;
		i++;
	}
	ft_control(str);
	i = 0;
	if (neg == -1)
		i++;
	sayi = ft_func(str, sayi, neg, i);
	return (sayi * neg);
}
