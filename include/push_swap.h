/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:36:33 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 09:04:00 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include "../libft/libft.h"

# define PB 1
# define RA 2
# define RRA 3
# define PA 4
# define RB 5
# define RRB 6
# define SB 7
# define SA 8
/*
typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;
*/
typedef struct s_var
{
	char	*line;
	char	**split;
	char	**argv;
	int		argc;
	int		len;
	int		print;
	int		color;
	int		fd;
	t_list	*a;
	t_list	*b;
}	t_var;

/*Operations*/
void	rr_list(t_list **a, t_list *tmp);
void	p_list(t_list **a, t_list **b, t_list *tmp);
void	r_list(t_list **a);
void	s_list(t_list **a);

/*Sorter*/
int		check_sort(t_list **a, int len);
void	check_dup(char **argv);
int		check_digits(char **argv);
int		check_pivot(t_list *a, int pivot, int flag);
void	pick_case(t_list **a, t_list **b, int c, t_var *v);
void	sort_short(t_list **a, t_list **b, int len, t_var *v);
void	sort_big(t_list **a, t_list **b, int len, t_var *v);
void	normalize_a(t_list **a, t_list **b, t_var *v, int min);
void	normalize_b(t_list **a, t_list **b, t_var *v, int min);

/*Utils*/
t_var	*ft_init_var(t_var *v);
t_list	*fill_list(t_var *v, char **split, t_list *tmp);
t_list	*ft_lst_dup(t_list *stack);
t_list	*ft_lstsort(t_list *stack);

/*List Auxiliary Functions*/
int		list_size(t_list *a);
void	free_list(t_list **stack);
t_list	*ft_lst_bottom(t_list *a);
int		ft_lstnbr(t_list **stack, int index);
int		get_min(t_list *stack);
int		get_max(t_list *stack);
int		get_index(t_list *stack, int num, int flag);
int		get_pivot(t_list *stack);

#endif
