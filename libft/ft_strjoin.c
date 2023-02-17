/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:34:53 by eablak            #+#    #+#             */
/*   Updated: 2022/12/19 12:31:12 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*united;
	size_t	j;

	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	united = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (united == NULL)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		united[i] = s1[i];
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (united);
}
