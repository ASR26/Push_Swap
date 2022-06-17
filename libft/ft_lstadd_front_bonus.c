/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 08:59:10 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/17 08:22:08 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_front(t_list **a, t_list *new)
{
	new->next = *a;
	new->previous = NULL;
	if (*a != NULL)
		(*a)->previous = new;
	*a = new;
}
