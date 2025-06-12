/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:26:56 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/11 15:49:31 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **stack1)
{
	t_list	*tmp;
	int		biggest_key;

	if (ft_is_sorted(stack1))
		return ;
	tmp = *stack1;
	biggest_key = 0;
	while (tmp)
	{
		if (tmp->key > biggest_key)
			biggest_key = tmp->key;
		tmp = tmp->next;
	}
	if ((*stack1)->key == biggest_key)
		rotate(stack1, 1);
	else if ((*stack1)->next->key == biggest_key)
		reverse_rotate(stack1, NULL, 1, "rra\n");
	if ((*stack1)->key > (*stack1)->next->key)
		swap(stack1, NULL, 1);
}

void	ft_simple_sort(t_list **stack1, t_list **stack2, int len)
{
	int	iterations_count;
	int	n;
	int	min_key;

	n = len;
	iterations_count = 0;
	while (iterations_count++ < len - 3)
	{
		min_key = ft_get_min_key(stack1);
		if (ft_rotations_count(stack1, min_key) <= ft_lstsize(*stack1)
			- ft_rotations_count(stack1, min_key))
			while ((*stack1)->key != min_key)
				rotate(stack1, 1);
		else
			while ((*stack1)->key != min_key)
				reverse_rotate(stack1, stack2, 1, "rra\n");
		if (ft_is_sorted(stack1) && ft_lstsize(*stack2) == 0)
			return ;
		push(stack1, stack2, 2);
		n--;
	}
	ft_sort_three(stack1);
	iterations_count = 0;
	while (iterations_count++ < len - 3)
		push(stack2, stack1, 1);
}

void	ft_ksort1(t_list **stack1, t_list **stack2)
{
	int	i;
	int	funnel;

	i = 0;
	funnel = ft_sqrt(ft_lstsize(*stack1)) * 133 / 100;
	while (*stack1)
	{
		if ((*stack1)->key <= i)
		{
			push(stack1, stack2, 2);
			rotate(stack2, 2);
			i++;
		}
		else if ((*stack1)->key <= i + funnel)
		{
			push(stack1, stack2, 2);
			i++;
		}
		else
			rotate(stack1, 1);
	}
}

void	ft_ksort2(t_list **stack1, t_list **stack2, int len)
{
	int	rotations_count;
	int	rrotations_count;

	while (len - 1 >= 0)
	{
		rotations_count = ft_rotations_count(stack2, len - 1);
		rrotations_count = ft_lstsize(*stack2) - rotations_count;
		if (rotations_count <= rrotations_count)
		{
			while ((*stack2)->key != len - 1)
				rotate(stack2, 2);
			push(stack2, stack1, 1);
			len--;
		}
		else
		{
			while (rrotations_count > 0)
			{
				reverse_rotate(stack1, stack2, 2, "rrb\n");
				rrotations_count--;
			}
			push(stack2, stack1, 1);
			len--;
		}
	}
}

void	ft_sort(t_list **stack1, t_list **stack2)
{
	int	size;

	size = ft_lstsize(*stack1);
	if (ft_is_sorted(stack1))
		return ;
	if (size == 2)
		swap(stack1, NULL, 1);
	else if (size == 3)
		ft_sort_three(stack1);
	else if (size <= 7)
		ft_simple_sort(stack1, stack2, ft_lstsize(*stack1));
	else
	{
		ft_ksort1(stack1, stack2);
		ft_ksort2(stack1, stack2, ft_lstsize(*stack2));
	}
}
