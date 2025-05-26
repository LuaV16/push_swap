/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:15:44 by lvargas-          #+#    #+#             */
/*   Updated: 2025/05/26 21:44:41 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
int	*ft_num_list(char *argv[], int count)
{
	int			*num_list;
	int			n;
	int			i;
	long long	tmp;

	num_list = (int *)malloc(count * sizeof(int));
	if (!num_list)
		return (NULL);
	n = 1;
	i = 0;
	while (argv[n])
	{
		while (*argv[n] != '\0')
		{
			if (ft_isdigit(*argv[n]) || *argv[n] == '-')
			{
				if (ft_atoi(&argv[n], &tmp) == 1 || tmp > INT_MAX
					|| tmp < INT_MIN)
					return (free(num_list), NULL);
				num_list[i] = (int)tmp;
				i++;
			}
			else
				argv[n]++;
		}
		n++;
	}
	return (num_list);
}

int	ft_check_list(int *list, int count)
{
	int	n;
	int	i;

	n = 0;
	while (list[n])
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

int	main(int argc, char *argv[])
{
	int	n;
	int	count;
	int	*num_list;

	if (argc == 1)
		return (0);
	n = argc - 1;
	while (n >= 1)
	{
		if (ft_check_error(argv[n]) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		n--;
	}
	count = ft_count_numbers(argv);
	num_list = ft_num_list(argv, count);
	if (!num_list[0] || ft_check_list(num_list, count) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("Numeros: %i\n", count);
	n = 0;
	while (num_list[n])
	{
		printf("%i ", num_list[n]);
		n++;
	}
	printf("\n");
	return (0);
}
