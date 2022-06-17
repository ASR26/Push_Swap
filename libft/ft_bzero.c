/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:22:58 by asolano-          #+#    #+#             */
/*   Updated: 2022/06/16 13:01:07 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Esta función sustituye n veces los bytes en la memoria dada por bytes nulos*/
#include"libft.h"

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}
