/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:33:01 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/15 11:15:14 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta función aloja suficiente memoria para copiar s1, hace la copia y devuelve
 * un puntero al string, si no hay suficiente memoria devuelve 0*/
#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		str_length;
	int		i;

	i = 0;
	str_length = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof (char) * str_length);
	if (!s2)
		return (0);
	while (*(s1 + i))
	{
		s2[i] = *(s1 + i);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
