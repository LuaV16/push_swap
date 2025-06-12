/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:24:08 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/11 14:13:30 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				key;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_atoi(char **nptr, long long *n);
int					ft_sqrt(int n);
int					ft_check_error(char *argv);
int					ft_count_numbers(char *argv[]);
int					ft_fill_list(char *argv[], int **num_list);
int					ft_num_list(char *argv[], int count, int **num_list);
int					ft_check_list(int *list, int count);
int					ft_rotations_count(t_list **stack, int key);
int					ft_lstsize(t_list *lst);
int					ft_is_sorted(t_list **stack1);
int					ft_get_min_key(t_list **stack);
int					ft_sqrt(int n);
int					ft_atoi(char **nptr, long long *n);
void				swap(t_list **stack1, t_list **stack2, int a);
void				push(t_list **stack1, t_list **stack2, int a);
void				rotate(t_list **stack1, int a);
void				reverse_rotate(t_list **stack1, t_list **stack2, int a,
						char *move);
void				ft_fill_stack_a(int *list, int size, t_list **lst);
void				ft_sort(t_list **stack1, t_list **stack2);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content, int key);
t_list				*ft_lstlast(t_list *lst);

#endif