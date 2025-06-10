/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:46:23 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/10 12:59:14 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char **nptr, long long *n)
{
	int negative;

	negative = 0;
	*n = 0;
	if (**nptr == '-')
	{
		if (**nptr == '-')
			negative = 1;
		(*nptr)++;
	}
	while (ft_isdigit(**nptr))
	{
		*n += **nptr - '0';
		if (ft_isdigit(*(*nptr + 1)))
			*n = *n * 10;
		(*nptr)++;
	}
	if (negative == 1)
		*n *= -1;
	return (0);
}
