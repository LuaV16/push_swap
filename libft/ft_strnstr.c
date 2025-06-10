/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:49:08 by lvargas-          #+#    #+#             */
/*   Updated: 2025/04/15 12:45:41 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	if (!*little)
		return ((char *)big);
	while (big[n] && n < len)
	{
		i = 0;
		while (little[i] && (n + i) < len && big[n + i] == little[i])
			i++;
		if (!little[i])
			return ((char *)(big + n));
		n++;
	}
	return (NULL);
}
