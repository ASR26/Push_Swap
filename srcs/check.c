/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 08:28:16 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/17 12:39:11 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check_sort comprueba que la lista esté bien rellena
*/
int	check_sort(t_list **a, int len)
{
	t_list	*tmp;

	if (list_size(*a) != len)
		return (0);
	(void)len;
	tmp = *a;
	while (tmp && tmp->next)
	{
		if ((tmp)->next != NULL && tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

/*
** Check_dup comprueba que no haya números duplicados en la lista
*/
void	check_dup(char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (argv[i])
	{
		tmp = ft_strdup(argv[i]);
		j = 0;
		while (argv[j])
		{
			if (j == i)
				j++;
			else if (ft_strcmp(tmp, argv[j]) == 0)
			{
				ft_free_arg(&tmp);
				write (1, "Error\n", 6);
				exit(1);
			}
			else
				j++;
		}
		ft_free_arg(&tmp);
		i++;
	}
}

/*
** Check_overflow comprueba que no haya overflows
*/

int	check_overflow(char *arg)
{
	long long	tmp;

	tmp = ps_atoll(arg);
	if (tmp >= INT_MIN && tmp <= INT_MAX && ft_strlen(arg) < 12)
		return (1);
	return (0);
}

/*
** Check_digits comprueba que los argumentos sean números
*/
int	check_digits(char **argv)
{
	int	i;
	int	j;

	i = -1;
	if (!argv[0])
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	while (argv[++i])
	{
		j = -1;
		if (check_overflow(argv[i]) == 0)
		{
			write (1, "Error\n", 6);
			exit (1);
		}
		while (argv[i][++j])
		{
			if (ft_isalpha(argv[i][j]) == 1 || argv[i][j] == '.'
			|| ((argv[i][j]) == '-' && (argv[i][j + 1]) == '\0')
			|| ((argv[i][j]) == '+' && (argv[i][j + 1]) == '\0'))
			{
				write (1, "Error\n", 6);
				exit (1);
			}
		}
	}
	return (1);
}

/*
** Check_pivot comprueba que la flag sea 1, relacionado con el stack 'a' donde
** es importante saber si el número es menor o igual que el pivote
**
** si la flag es 2 comprobamos si el número es el pivote
*/
int	check_pivot(t_list *a, int pivot, int flag)
{
	while (a)
	{
		if (flag == 1)
		{
			if (a->content <= pivot)
				return (1);
			a = a->next;
		}
		if (flag == 2)
		{
			if (a->content == pivot)
				return (1);
			a = a->next;
		}
	}
	return (0);
}
