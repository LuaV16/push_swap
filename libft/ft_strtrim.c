/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:41:01 by lvargas-          #+#    #+#             */
/*   Updated: 2025/04/16 15:10:53 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s1, char const *set)
{
	size_t		n;
	char const	*start;

	n = 0;
	start = set;
	while (*s1)
	{
		set = start;
		while (*set)
		{
			if (*s1 == *set)
			{
				n += 1;
				break ;
			}
			set++;
			if (!*set)
			{
				return (n);
			}
		}
		s1++;
	}
	return (n);
}

static size_t	ft_count_rev(char const *s1, char const *set)
{
	size_t		n;
	int			len;
	char const	*start;

	n = 0;
	start = set;
	len = ft_strlen(s1) - 1;
	while (len >= 0)
	{
		set = start;
		while (*set)
		{
			if (s1[len] == *set)
			{
				n += 1;
				break ;
			}
			set++;
			if (!*set)
				return (n);
		}
		len--;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	n;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	n = ft_count(s1, set);
	if (n >= (ft_strlen(s1) - ft_count_rev(s1, set)))
		return (ft_strdup(""));
	ptr = (char *)malloc((ft_strlen(s1) - ft_count(s1, set) - ft_count_rev(s1,
					set) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (n < (ft_strlen(s1) - ft_count_rev(s1, set)))
	{
		ptr[i] = (char)s1[n];
		n++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
