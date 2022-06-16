/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:28:21 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/15 08:46:19 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Este archivo contiene las operaciones que pasan elementos de un stack a otro
*/
void	p_list(t_list **a, t_list **b, t_list *tmp)
{
	tmp = NULL;
	if (*b == NULL && *a)
	{
		*b = (t_list *)malloc(sizeof (t_list));
		(*b)->previous = NULL;
		(*b)->content = (*a)->content;
		(*b)->next = NULL;
		*a = (*a)->next;
		(*a)->previous = NULL;
	}
	else
	{
		if (*a)
		{
			tmp = (t_list *)malloc(sizeof(t_list));
			tmp->content = (*a)->content;
			tmp->next = NULL;
			tmp->previous = NULL;
			ft_lstadd_front(b, tmp);
			*a = (*a)->next;
		}
	}
}
