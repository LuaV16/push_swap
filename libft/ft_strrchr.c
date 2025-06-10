/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:29:04 by lvargas-          #+#    #+#             */
/*   Updated: 2025/04/14 14:51:03 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*coincidence;
	char	*ptr;

	coincidence = NULL;
	ptr = (char *)s;
	while (1)
	{
		if ((unsigned char)*ptr == (unsigned char)c)
		{
			coincidence = ptr;
		}
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	return (coincidence);
}
