/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 08:47:32 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/15 09:29:51 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*str;

	str = (t_list *)malloc(sizeof (t_list));
	if (!str)
		return (str = 0);
	str->next = 0;
	str->content = content;
	return (str);
}
