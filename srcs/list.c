/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:56:40 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 09:05:46 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_list(t_var *v, char **split, t_list *tmp)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		tmp = malloc(sizeof (t_list));
		if (tmp == NULL)
			return (NULL);
		tmp->content = ft_atoi(split[i]);
		if (tmp->content > INT_MAX || tmp->content < INT_MIN)
			exit(1);
		tmp->next = NULL;
		tmp->previous = NULL;
		ft_lstadd_back(&v->a, tmp);
		tmp = NULL;
	}
	return (v->a);
}
