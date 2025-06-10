/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:08:29 by lvargas-          #+#    #+#             */
/*   Updated: 2025/04/16 12:36:41 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	i;
	char	*ptr;

	n = 0;
	i = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[n] != '\0')
	{
		ptr[n] = (char)s1[n];
		n++;
	}
	while (s2[i] != '\0')
	{
		ptr[n] = (char)s2[i];
		i++;
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
