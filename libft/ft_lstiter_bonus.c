/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:07:34 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/15 09:32:06 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	if (lst == 0)
		return ;
	while (lst->next != 0)
	{
		(f)(lst->content);
		lst = lst->next;
	}
	(f)(lst->content);
}
