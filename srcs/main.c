/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:47:56 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 09:09:02 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**		Push-Swap es una aplicación que ordena una serie de números en orden
** creciente.
**		La función main se encarga de iniciar la aplicación, recibiendo el
** nombre de la aplicación y un argumento.
**		Por ejemplo: ./push_swap "5 6 1 4 7"
**
**		El primero paso consiste en validar el argumento recibido y si es
** correcto rellenar el stack 'a' con los números.
**		El siguiente paso consiste en llamar a la funcion sorter que es
** responsable de conocer el tamaño de la lista que sevirá para hacer mejor el
** algoritmo lógico.
**	
**		Esta aplicación usará dos stacks que servirán para intercambiar números
** y así ordenar la lista.
**		También hay algunas operaciones que deben ser usadas:
**	-sa: swap 'a' - intercambia el primer y segundo elemento del stack 'a'
**	-sb: swap 'b' - intercambia el primer y segundo elemento del stack 'b'
**	-ss: sa y sb a la vez
**	-pa: push 'a' - mover el primer elemento de 'a' al primer elemento de 'b'
**	-pb: push 'b' - mover el primer elemento de 'b' al primer elemento de 'a'
**	-ra: rotate 'a' - mover todos los elemento de 'a' 1 hacia arriba
**	-rb: rotate 'b' - mover todos los elemento de 'b' 1 hacia arriba
**	-rr: ra y rb a la vez
**	-rra: rotate 'a' - mover todos los elemento de 'a' 1 hacia abajo
**	-rrb: rotate 'b' - mover todos los elemento de 'b' 1 hacia abajo
**	-rrr: rra y rrb a la vez
**
**
**		El resultado es la secuencia de operaciones que hace la aplicación
** para ordenar la lista de números.
*/

/*
** fill_list identifica si el argumento es una string de números o una secuencia
** de números y llena el stak 'a' con los parámetros
*/

char	**fill_args(t_var *v, int argc, char **argv)
{
	v->fd = 1;
	if (argc == 2)
		v->split = ft_split(argv[1], ' ');
	else
		v->split = &argv[1];
	return (v->split);
}

/*
** Esto es el núcleo de la lógica, cuando la lista es válida
** Si todo está bien verifica la longitud de la lista, si es menor de 11 (corta)
** sigue el proceso de ordenar hasta 10 números, si tiene más usará el método
** para ordenar listas largas
*/
void	push_swap(t_var *v, int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	v->split = fill_args(v, argc, argv);
	check_dup(v->split);
	check_digits(v->split);
	v->a = fill_list(v, v->split, list);
	if (check_sort(&v->a, list_size(v->a)) == 1)
		return ;
	v->len = list_size(v->a);
	free_list(&list);
	if (v->len <= 10)
		sort_short(&(v->a), &(v->b), v->len, v);
	else
		sort_big(&(v->a), &(v->b), v->len, v);
	if (argc == 2 || (argc == 3 && v->fd != 1))
		free(v->split);
	close(v->fd);
}

int	main(int argc, char **argv)
{
	t_var	*v;

	v = NULL;
	if (argc < 2)
		return (0);
	else
	{
		v = ft_init_var(v);
		push_swap(v, argc, argv);
		free(v);
		v = NULL;
	}
}
