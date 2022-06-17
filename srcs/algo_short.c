/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 08:29:38 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/17 11:48:51 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** La función normalize se encarga de la smart rotation.
** Usamos el valor más bajo como índice de comparación con la posición
** encontrada (num), num encontrará donde está el mejor número más pequeño
** y lo rotará de acuerdo a esto
*/
void	normalize(t_list **a, t_list **b, t_var *v, int min)
{
	int	index;
	int	num;

	index = get_index(*a, min, 1);
	num = (list_size((*a)) / 2);
	if (num > index)
		pick_case(a, b, RA, v);
	else
		pick_case(a, b, RRA, v);
}

/*
** El método usará el valor más bajo como parámetro
** Si el segundo número es el valor más bajo hará un swap
** si el primer elemento es el más bajo se enviará al stack 'b'
**
** Por otro lado mientras el número más bajo no llegue arriba hará smart
** rotation hasta llegar, una vez llegue se envía al stack 'b'
** Esto se repite hasta que queden 3 números
*/
void	case_with_10(t_list **a, t_list **b, int len, t_var *v)
{
	int		i;
	int		min;
	t_list	*tmp1;
	t_list	*tmp2;

	i = len;
	while (i > 3)
	{
		min = get_min(*a);
		tmp1 = (*a)->next;
		if ((*a)->content != min && tmp1 && tmp1->content == min)
			pick_case(a, b, SA, v);
		while (min != (*a)->content)
			normalize(a, b, v, min);
		if (min == (*a)->content)
		{
			tmp2 = *a;
			pick_case(a, b, PB, v);
			free(tmp2);
			i--;
		}
	}
}

/*
** Esto hará ambas operaciones, siendo la primera 'sa'
*/
void	sort_3(t_list **a, t_list **b, t_var *v, int op)
{
	pick_case(a, b, SA, v);
	pick_case(a, b, op, v);
}

/*
** Este comprobador primero encuentra el elemento más bajo
**
** - Primer caso: si el primer número es menor que el segundo y
**  el tercero es el mínimo envía el último al primer lugar (rra)
** - Segundo caso: si el primer número es más grande que el segundo
**   y el tercero es el mínimo cambia el primero y el segundo y 
**   manda el tercero al primer lugar (sa, rra)
** - Tercer caso: si el minimo es el segundo número, comprobará si 
**   el primero es mayor que el tercero y los cambiará apropiadamente
**  - Cuarto caso: si el primer número es el menor y el segundo es menor
**  que el tercero
*/
void	case_with_3(t_list **a, t_list **b, int len, t_var *v)
{
	t_list	*tmp;
	int		min;

	tmp = ft_lst_bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->content < (*a)->next->content && tmp->content == min)
			pick_case(a, b, RRA, v);
		else if ((*a)->content > (*a)->next->content && tmp->content == min)
			sort_3(a, b, v, RRA);
		else if ((*a)->next->content == min)
		{
			if ((*a)->content < tmp->content)
				pick_case(a, b, SA, v);
			else if ((*a)->content > tmp->content)
				pick_case(a, b, RA, v);
		}
		else if ((*a)->content == min && (*a)->next->content > tmp->content)
			sort_3(a, b, v, RA);
	}
}

/*
** Este comprobador mira si el stack tiene las condiciones y ejecuta las
** operaciones necesarias
**
** Si len = 2 y el primer número es mayor que el último hará 'sa'
** si len = 3 entrará a case_with_3; para cualquier longitud 3 > len >= 1
** usará la lógica de mandar los 1-7 números más grandes a 'b' dependiendo
** de la longitud de la lista (si son 10 números mandará 7)
** Después ordenará los 3 números restantes y mandará los de 'b' en el orden
** correcto
**
** Liberando toda la memoria guardada en el stack 'a' y el 'b'
*/
void	sort_short(t_list **a, t_list **b, int len, t_var *v)
{
	t_list	*tmp;

	tmp = NULL;
	if (len == 2 && (*a)->content > (*a)->next->content)
		pick_case(a, b, SA, v);
	if (len <= 3)
		case_with_3(a, b, len, v);
	else if (len > 3)
	{
		case_with_10(a, b, len, v);
		case_with_3(a, b, 3, v);
		while (*b)
		{
			tmp = *b;
			pick_case(a, b, PA, v);
			free(tmp);
		}
		free_list(b);
	}
	free_list(a);
}
