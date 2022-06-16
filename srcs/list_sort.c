/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:04:06 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/14 12:39:32 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_lstnbr devuelve el número asociado al índice recibido
*/
int	ft_lstnbr(t_list **stack, int index)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (i == index)
			return (tmp->content);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_lstswap(t_list *x, t_list *y)
{
	int	tmp;

	tmp = x->content;
	x->content = y->content;
	y->content = tmp;
}

/*
** Esta función ordena la lista que sera usada como base para la lógica y el
** algoritmo
*/
t_list	*ft_lstsort(t_list *stack)
{
	t_list	*base;
	t_list	*tmp;
	t_list	*cmp;

	base = NULL;
	base = stack;
	tmp = NULL;
	cmp = NULL;
	while (base->next)
	{
		cmp = base;
		tmp = base->next;
		while (tmp)
		{
			if (cmp->content > tmp->content)
				cmp = tmp;
			tmp = tmp->next;
		}
		ft_lstswap(base, cmp);
		base = base->next;
	}
	return (stack);
}
