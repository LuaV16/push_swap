/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:49:50 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/11 14:13:54 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack1, t_list **stack2, int a)
{
	t_list	*first;
	t_list	*second;

	if (a == 1 || a == 3)
	{
		first = *stack1;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack1 = second;
	}
	if (a == 2 || a == 3)
	{
		first = *stack2;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack2 = second;
	}
	if (a == 1)
		write(1, "sa\n", 3);
	else if (a == 2)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
}

void	push(t_list **stack_src, t_list **stack_dest, int a)
{
	t_list	*stack_src_second;

	if (!(*stack_src))
		return ;
	stack_src_second = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = stack_src_second;
	if (a == 1)
		write(1, "pa\n", 3);
	else if (a == 2)
		write(1, "pb\n", 3);
}

void	rotate(t_list **stack1, int a)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack1) || !(*stack1)->next)
		return ;
	first = *stack1;
	last = ft_lstlast(*stack1);
	*stack1 = first->next;
	first->next = NULL;
	last->next = first;
	if (a == 1)
		write(1, "ra\n", 3);
	else if (a == 2)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_list **stack1, t_list **stack2, int a, char *move)
{
	t_list	*last;
	t_list	*second_last;

	if (a == 1 || a == 3)
	{
		last = ft_lstlast(*stack1);
		second_last = *stack1;
		while (second_last->next != last)
			second_last = second_last->next;
		last->next = *stack1;
		*stack1 = last;
		second_last->next = NULL;
	}
	if (a == 2 || a == 3)
	{
		last = ft_lstlast(*stack2);
		second_last = *stack2;
		while (second_last->next != last)
			second_last = second_last->next;
		last->next = *stack2;
		*stack2 = last;
		second_last->next = NULL;
	}
	write(1, move, 4);
}
