/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:49:50 by lvargas-          #+#    #+#             */
/*   Updated: 2025/05/29 16:08:46 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	write(1, "")
}

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*stack2_second;

	if (!stack1 || !stack2)
		return ;
	stack2_second = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = stack2_second;
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second;

	last = ft_lstlast(*stack);
	second = (*stack)->next;
	last->next = *stack;
	(*stack)->next = NULL;
	*stack = second;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	last = ft_lstlast(*stack);
	second_last = *stack;
	while (second_last->next != last)
	{
		second_last = second_last->next;
	}
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
}
