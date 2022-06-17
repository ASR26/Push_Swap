/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:20:50 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 13:12:44 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Estas funciones están para elegir la mejor forma de rotar
*/
void	normalize_a(t_list **a, t_list **b, t_var *v, int pivot)
{
	int	index;
	int	num;

	index = get_index((*a), pivot, 1);
	num = (list_size(*a) / 2);
	if (index < num)
		pick_case(a, b, RA, v);
	else
		pick_case(a, b, RRA, v);
}

void	normalize_b(t_list **a, t_list **b, t_var *v, int pivot)
{
	int	index;
	int	num;

	index = get_index((*b), pivot, 2);
	num = ft_abs((list_size((*b)) / 2));
	if (index < num && *b)
		pick_case(a, b, RB, v);
	else if (*b)
		pick_case(a, b, RRB, v);
}
