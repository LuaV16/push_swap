/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:49:23 by lvargas-          #+#    #+#             */
/*   Updated: 2025/04/14 13:42:53 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	ptrdest = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*ptrdest = *ptrsrc;
		ptrdest++;
		ptrsrc++;
		i++;
	}
	return (dest);
}
