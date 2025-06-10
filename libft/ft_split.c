/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:13:02 by lvargas-          #+#    #+#             */
/*   Updated: 2025/04/16 17:46:10 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	n;
	size_t	i;
	int		check;

	check = 0;
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && check == 0)
		{
			check = 1;
			n += 1;
		}
		if (s[i] == c && check == 1)
		{
			check = 0;
		}
		i++;
	}
	return (n);
}

static void	ft_free_split(char **ptr)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static char	**ft_empty(void)
{
	char	**ptr;

	ptr = (char **)malloc(1 * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr[0] = NULL;
	return (ptr);
}

static char	**ft_fill(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			ptr[j] = ft_substr(s, start, i - start);
			if (!ptr[j])
				return (ft_free_split(ptr), NULL);
			j++;
		}
		else
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count(s, c);
	if (words == 0)
		return (ft_empty());
	ptr = (char **)malloc((words + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ft_fill(ptr, s, c));
}
