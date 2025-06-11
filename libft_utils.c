/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:19:12 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/10 16:17:55 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

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

int	ft_sqrt(int n)
{
	int	i;

	if (n < 4)
		return (1);
	i = 2;
	while (i * i < n)
		i++;
	if (i * i > n)
	{
		if ((i * i - n) < (n - (i - 1) * (i - 1)))
    		return (i);
	}
	return (i - 1);
}
