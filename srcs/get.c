/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:59:07 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 12:22:12 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** El índice actuará como base para rotar los números en dos situaciones.
** Flag '1' ocurrirá cuando el número que compruebas es el más pequeño del
** stack, Flag '2' ocurrirá cuando se le asigne el número máximo al índice
*/
int	get_index(t_list *stack, int num, int flag)
{
	int	i;

	i = 1;
	if (flag == 1)
	{
		while (stack)
		{
			if (stack->content <= num)
				return (i);
			stack = stack->next;
			i++;
		}
	}
	if (flag == 2)
	{
		while (stack)
		{
			if (stack->content >= num)
				return (i);
			stack = stack->next;
			i++;
		}
	}
	return (-1);
}

/*
** Hay un rango de eficiencia dependiendo del tamaño de la lista
*/
int	get_pivot(t_list *stack)
{
	t_list	*tmp;
	int		len;
	int		pivot;

	pivot = 0;
	len = 0;
	tmp = NULL;
	len = list_size(stack);
	tmp = ft_lstsort(stack);
	if (len <= 10)
		pivot = ft_abs(len / 2);
	else if (len > 10 && len < 200)
		pivot = ft_abs(len / 4);
	else if (len >= 200)
		pivot = ft_abs(len / 8);
	return (ft_lstnbr(&tmp, pivot));
}

/*
** Esta funcion buscará el número máximo en el stack
*/
int	get_max(t_list *stack)
{
	int		max;
	t_list	*tmp;

	max = 0;
	tmp = NULL;
	if (stack)
	{
		max = stack->content;
		tmp = stack;
		while (stack)
		{
			if (stack->content >= max)
				max = stack->content;
			stack = stack->next;
		}
		stack = tmp;
	}
	return (max);
}

/*
** Esta función busca el valor mínimo en el stack
*/
int	get_min(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}
