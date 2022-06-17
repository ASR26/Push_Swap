/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:38:51 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 12:19:56 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Este archivo tiene un metodo de comprobación para elegir la operación
** correcta para aplicar a ambos stacks
*/
void	next_next_case(t_list **a, t_list **b, int c, t_var *v)
{
	t_list	*tmp;

	tmp = NULL;
	if (c == 7 && list_size(*b) > 1)
	{
		ft_putstr_fd("sb\n", v->fd);
		s_list(b);
	}
	else if (c == 8 && list_size(*a) > 1)
	{
		ft_putstr_fd("sa\n", v->fd);
		s_list(a);
	}
}

void	next_case(t_list **a, t_list **b, int c, t_var *v)
{
	t_list	*tmp;

	tmp = NULL;
	if (c == 4)
	{
		ft_putstr_fd("pa\n", v->fd);
		p_list(b, a, tmp);
		free(tmp);
	}
	else if (c == 5 && list_size(*b) > 1)
	{
		ft_putstr_fd("rb\n", v->fd);
		r_list(b);
		free(tmp);
	}
	else if (c == 6 && list_size(*b) > 1)
	{
		ft_putstr_fd("rrb\n", v->fd);
		rr_list(b, tmp);
		free(tmp);
	}
	else
		next_next_case(a, b, c, v);
}

void	pick_case(t_list **a, t_list **b, int c, t_var *v)
{
	t_list	*tmp;

	tmp = NULL;
	if (c == 1)
	{
		ft_putstr_fd("pb\n", v->fd);
		p_list(a, b, tmp);
		free(tmp);
	}
	else if (c == 2)
	{
		ft_putstr_fd("ra\n", v->fd);
		r_list(a);
		free(tmp);
	}
	else if (c == 3 && list_size(*a) > 1)
	{
		ft_putstr_fd("rra\n", v->fd);
		rr_list(a, tmp);
	}
	else
		next_case(a, b, c, v);
}
