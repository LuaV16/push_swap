/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:23:09 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/10 16:55:02 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(char *argv)
{
	int	n;
	int	no_digit_flag;

	no_digit_flag = 0;
	n = 0;
	while (argv[n] != '\0')
	{
		if (!ft_isdigit(argv[n]) && !ft_isspace(argv[n]))
			if (argv[n] != '-' || (argv[n] == '-' && !ft_isdigit(argv[n + 1])))
				no_digit_flag = 1;
		n++;
	}
	return (no_digit_flag);
}

int	ft_count_numbers(char *argv[])
{
	int	n;
	int	i;
	int	count;
	int	in_number;

	n = 1;
	count = 0;
	while (argv[n])
	{
		i = 0;
		in_number = 0;
		while (argv[n][i] != '\0')
		{
			if ((argv[n][i] == '-' || ft_isdigit(argv[n][i])) && in_number == 0)
			{
				count++;
				in_number = 1;
			}
			if (ft_isspace(argv[n][i]))
				in_number = 0;
			i++;
		}
		n++;
	}
	return (count);
}

int	ft_fill_list(char *argv[], int **num_list)
{
	int			n;
	int			i;
	long long	tmp;

	n = 1;
	i = 0;
	while (argv[n])
	{
		while (*argv[n] != '\0')
		{
			if (ft_isdigit(*argv[n]) || *argv[n] == '-')
			{
				ft_atoi(&argv[n], &tmp);
				if (tmp > INT_MAX || tmp < INT_MIN)
					return (1);
				(*num_list)[i] = (int)tmp;
				i++;
			}
			else
				argv[n]++;
		}
		n++;
	}
	return (0);
}

int	ft_num_list(char *argv[], int count, int **num_list)
{
	int			error;

	*num_list = (int *)malloc(count * sizeof(int));
	if (!*num_list)
		return (1);
	error = ft_fill_list(argv, num_list);
	if (error == 1)
		return (free(*num_list), 1);
	return (0);
}

int	ft_check_list(int *list, int count)
{
	int n;
	int i;

	n = 0;
	while (n < count)
	{
		i = n + 1;
		while (i < count)
		{
			if (list[i] == list[n])
				return (1);
			else
				i++;
		}
		n++;
	}
	return (0);
}
