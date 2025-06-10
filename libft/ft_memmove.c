/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:14:50 by lvargas-          #+#    #+#             */
/*   Updated: 2025/04/14 16:22:39 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	unsigned long	ncopy;
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	i = 0;
	ncopy = n - 1;
	if (dest < src)
		ptrdest = ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		while (i < n)
		{
			*(ptrdest + ncopy) = *(ptrsrc + ncopy);
			ncopy--;
			i++;
		}
	}
	return (dest);
}
