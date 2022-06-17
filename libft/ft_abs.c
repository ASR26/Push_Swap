/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:28:40 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 12:15:02 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(float num)
{
	int	tmp;

	tmp = (int)num;
	if ((num - tmp) >= 0.5)
		return ((int) num + 1);
	else
		return ((int) num);
}
