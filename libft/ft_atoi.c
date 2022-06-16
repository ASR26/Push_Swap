/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:40:58 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 08:47:07 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta función te convierte los números de un string en un entero*/
#include"libft.h"
#include<stdio.h>

long long	ps_atoll(char *s)
{
	int					i;
	int					neg;
	unsigned long long	ret;

	i = 0;
	ret = 0;
	neg = 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == ' ')
		i++;
	if (s[i] == '-')
		neg = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = 10 * ret + s[i] - '0';
		i++;
	}
	ret = ret * neg;
	return (ret);
}

int	ps_atoi(char *s)
{
	int					i;
	int					neg;
	unsigned long long	ret;

	i = 0;
	ret = 0;
	neg = 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == ' ')
		i++;
	if (s[i] == '-')
		neg = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		ret = 10 * ret + s[i] - '0';
		i++;
	}
	ret = ret * neg;
	return ((int)ret);
}

int	ft_manage_longmin(unsigned long result, int count)
{
	int	value;

	if (count % 2 != 0)
		value = -1;
	else
		value = 1;
	if (value == -1 && result > 2147483648)
		return (0);
	else if (value == 1 && result > 2147483647)
		result = (-1);
	return (result * value);
}

int	ft_atoi(char *str)
{
	int				i;
	int				count;
	unsigned long	result;

	i = 0;
	count = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (ft_manage_longmin(result, count));
}
