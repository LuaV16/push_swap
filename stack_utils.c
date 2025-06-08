/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:39:21 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/09 00:01:21 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_fill_key(t_list **lst)
{
	int i;
	t_list *save;
	t_list *min_node;

	i = 0;
	while (i < ft_lstsize(*lst))
	{
		min_node = NULL;
		save = *lst;
		while (save != NULL)
		{
			if (save->key == -1)
			{
				if (!min_node || save->content < min_node->content)
					min_node = save;
			}
			save = save->next;
		}
		if (min_node)
			min_node->key = i;
		i++;
	}
}

void ft_fill_stack_a(int *list, int size, t_list **lst)
{
	t_list *node;
	int i;
	
	i = 0;
	while(i < size)
	{
		node = ft_lstnew(list[i], -1);
		ft_lstadd_back(lst, node);
		i++;
	}
	ft_fill_key(lst);
}

int ft_rotations_count(t_list **stack, int key)
{
    int count;
    t_list *tmp;

    count = 0;
    tmp = *stack;
    while (tmp && tmp->key != key)
    {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

int	ft_is_sorted(t_list **stack1)
{
	int	n;
	t_list *tmp;

	tmp = *stack1;
	n = tmp->key;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (n > tmp->key)
			return (0);
		else
		{
			n = tmp->key;
			tmp = tmp->next;
		}
	}
	return (1);
}

int ft_get_min_key(t_list **stack)
{
	t_list *tmp;
	int min_key;

	if (*stack == NULL)
		return (-1);
	tmp = *stack;
	min_key = tmp->key;
	while (tmp != NULL)
	{
		if (tmp->key < min_key)
			min_key = tmp->key;
		tmp = tmp->next;
	}
	return (min_key);
}
