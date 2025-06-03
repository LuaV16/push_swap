/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:15:44 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/03 13:15:55 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	n;
	int	count;
	int	*num_list;
	t_list *stack_a;
	t_list *stack_b;

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
	n = 0;
	stack_a = NULL;
	stack_b = NULL;
	ft_fill_stack_a(num_list, count, &stack_a);
	ft_sort(&stack_a, &stack_b);
	free(num_list);
	printf("\n");
	return (0);
}
