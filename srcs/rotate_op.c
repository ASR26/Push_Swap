/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:48:12 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 09:05:06 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Este archivo tiene las operaciones de rotación
*/

t_list	*rr_swap(t_list *top, t_list *tmp)
{
	while (top->next)
		top = top->next;
	tmp->content = top->content;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}

void	rr_bottom(t_list **top)
{
	while (*top)
	{
		if ((*top)->next->next == NULL)
			break ;
		*top = (*top)->next;
	}
	free((*top)->next);
	(*top)->next = NULL;
}

void	rr_list(t_list **top, t_list *tmp)
{
	t_list	*a;

	a = NULL;
	tmp = NULL;
	if (*top)
	{
		tmp = (t_list *)malloc(sizeof (t_list));
		if (tmp == NULL)
			return ;
		tmp = rr_swap(*top, tmp);
		a = *top;
		rr_bottom(top);
		*top = a;
		ft_lstadd_front(top, tmp);
	}
}

void	r_list(t_list **top)
{
	t_list	*tmp;

	tmp = *top;
	if (*top)
	{
		*top = (*top)->next;
		ft_lstadd_back(top, tmp);
	}
}
