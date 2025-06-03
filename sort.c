/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:26:56 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/03 13:19:04 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list **stack1)
{
	int	n;

	n = (*stack1)->key;
	*stack1 = (*stack1)->next;
	while (*stack1 != NULL)
	{
		if (n > (*stack1)->key)
			return (0);
		else
		{
			n = (*stack1)->key;
			*stack1 = (*stack1)->next;
		}
	}
	return (1);
}

void	ft_sort(t_list **stack1, t_list **stack2)
{
	if (ft_is_sorted(stack1))
	{
		return ;
	}
	if (ft_lstsize(*stack1) == 2)
	{
		swap(stack1, NULL, 1);
	}
}
