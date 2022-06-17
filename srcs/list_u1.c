/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_u1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:34:32 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 12:56:07 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Este archivo tiene algunas funciones generales
*/

/*
** Esta función libera un stack si hace falta
*/
void	free_list(t_list **stack)
{
	t_list	*tmp;

	if (*stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = NULL;
			*stack = tmp;
		}
		free(*stack);
		*stack = NULL;
	}
}

/*
** Encuentra el tamaño de la lista recibida en el stack
*/
int	list_size(t_list *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

/*
** Esta función duplica una lista y devuelve el duplicado
*/
t_list	*ft_lst_dup(t_list *stack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = malloc(sizeof (t_list));
	ft_bzero(tmp1, sizeof (t_list));
	tmp2 = tmp1;
	while (stack)
	{
		tmp1->content = stack->content;
		if (stack->next)
		{
			tmp1->next = malloc(sizeof (t_list));
			ft_bzero(tmp1->next, sizeof (t_list));
			tmp1 = tmp1->next;
		}
		stack = stack->next;
	}
	tmp1 = tmp2;
	return (tmp1);
}

/*
** Encuentra el último elemento de la lista
*/
t_list	*ft_lst_bottom(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_back_r(t_list **top)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = NULL;
	tmp1 = *top;
	tmp2 = (*top)->previous;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	tmp1->next->previous = tmp1;
	tmp1->next->next = NULL;
}
