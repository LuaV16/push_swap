/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:15:44 by lvargas-          #+#    #+#             */
/*   Updated: 2025/05/27 13:39:18 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	if (ft_num_list(argv, count, &num_list) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!num_list || ft_check_list(num_list, count) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("Numeros: %i\n", count);
	n = 0;
	while (n < count)
	{
		printf("%i ", num_list[n]);
		n++;
	}
	free(num_list);
	printf("\n");
	return (0);
}
