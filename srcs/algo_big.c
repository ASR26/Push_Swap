/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:19:21 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 09:05:22 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** El algoritmo usado utiliza un pivote como referencia para las operaciones
** El "check_pivot" detecta si el primer número del stack 'a' es menor o igual
** que el pivote encontrado, el pivote en este caso será el valor más alto de
** la sección
**
** Conocidas las condiciones, empujará los números al stacj 'b', preparando
** las secciones de números para ordenar
**
** Si no cumple las condiciones hará una smart rotation del stack 'a'
*/
void	first_sort(t_list **a, t_list **b, int len, t_var *v)
{
	int		i;
	int		pivot;
	t_list	*tmp1;
	t_list	*tmp2;

	i = len;
	while (i >= ft_abs(len / 4))
	{
		tmp1 = ft_lst_dup(*a);
		pivot = get_pivot(tmp1);
		while (check_pivot((*a), pivot, 1) && (*a))
		{
			if ((*a)->content <= pivot)
			{
				tmp2 = *a;
				pick_case(a, b, PB, v);
				i--;
				free(tmp2);
			}
			else
				normalize_a(a, b, v, pivot);
		}
		free_list(&tmp1);
	}
}

/*
** Cuando solo queden los números grandes en el stack 'a' (desordenados)
** cogerá los números superiores de 'a' y los enviará a 'b' si es el
** número más pequeño, si no hara un smart rotate del stack
** Esto se repetirá mietras la lista tenga números
*/
void	second_sort(t_list **a, t_list **b, int len, t_var *v)
{
	int		min;
	t_list	*tmp;

	tmp = NULL;
	while (*a && !check_sort(a, len))
	{
		min = get_min(*a);
		tmp = (*a)->next;
		while ((*a)->content != min && tmp && tmp->content == min)
			pick_case(a, b, SA, v);
		while (list_size(*a) && check_pivot((*a), min, 1))
		{
			if ((*a)->content == min)
			{
				tmp = *a;
				pick_case(a, b, PB, v);
				free(tmp);
				len--;
			}
			else
				normalize_a(a, b, v, min);
		}
	}
}

/*
** Esta parte es la responsable de devolver los números en orden correcto
** El pivote (max) se iguala al valor más alto del stack 'b'
**
** Primero mientras el pivote y el primer elemento de b sean iguales empuja
** el número al stack 'a'
** Si no, hará smart rotation de 'b' hasta que el número sea igual al pivote,
** cuando será enviado al stack 'a'. Desoues de esto encontrará el numero 
** máximo otra vez para ajustarse al nuevo stack
**
** Al final el stack 'b' estará ordenado en el stack 'a'
*/
void	third_sort(t_list **a, t_list **b, int max, t_var *v)
{
	t_list	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = get_max(*b);
		while (check_pivot(*b, max, 2))
		{
			max = get_max(*b);
			tmp = (*b)->next;
			while ((*b)->content != max && tmp && tmp->content == max)
				pick_case(a, b, SB, v);
			while (((*b)->content != max) && *b)
				normalize_b(a, b, v, max);
			while (*b && (*b)->content == max)
			{
				tmp = *b;
				pick_case(a, b, PA, v);
				max = get_max(*b);
				free(tmp);
			}
		}
	}
}

void	sort_big(t_list **a, t_list **b, int len, t_var *v)
{
	int	max;

	max = 0;
	first_sort(a, b, len, v);
	second_sort(a, b, len, v);
	third_sort(a, b, max, v);
	free_list(a);
	free_list(b);
}
