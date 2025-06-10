/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:48:36 by naryko            #+#    #+#             */
/*   Updated: 2025/04/17 21:07:46 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(long n)
{
	size_t	result;

	result = 0;
	if (n < 0)
	{
		n *= -1;
		result++;
	}
	if (n == 0)
	{
		result++;
		return (result);
	}
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static char	*ft_create_number(char *ptr, long num)
{
	int	i;
	int	end;

	end = ft_count(num);
	i = ft_count(num) - 1;
	if (num == 0)
	{
		ptr[0] = '0';
	}
	if (num < 0)
	{
		num *= -1;
		ptr[0] = '-';
		i = ft_count(num);
		end = ft_count(num) + 1;
	}
	while (num > 0)
	{
		ptr[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	ptr[end] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*ptr;

	num = (long)n;
	ptr = (char *)malloc((ft_count(num) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_create_number(ptr, num);
	return (ptr);
}
