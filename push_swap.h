/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:24:08 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/03 13:16:12 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	int				key;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_atoi(char **nptr, long long *n);
int					ft_check_error(char *argv);
int					ft_count_numbers(char *argv[]);
int					ft_fill_list(char *argv[], int **num_list);
int					ft_num_list(char *argv[], int count, int **num_list);
int					ft_check_list(int *list, int count);
t_list	*ft_lstnew(void *content, int key);
t_list	*ft_lstlast(t_list *lst);
void	swap(t_list **stack1, t_list **stack2, int a);
void ft_fill_stack_a(int *list, int size, t_list **lst);
void	ft_sort(t_list **stack1, t_list **stack2);
int	ft_lstsize(t_list *lst);

#endif