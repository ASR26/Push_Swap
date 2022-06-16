/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:40:17 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 09:06:13 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Este archivo tiene las operaciones de intercambio en para los stacks
*/
void	s_list(t_list **top)
{
	int		i;
	int		j;

	if ((*top) && (*top)->next)
	{
		i = (*top)->content;
		j = (*top)->next->content;
		(*top)->content = j;
		(*top)->next->content = i;
	}
}
