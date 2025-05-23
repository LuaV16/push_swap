/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:15:44 by lvargas-          #+#    #+#             */
/*   Updated: 2025/05/23 16:56:57 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(char *argv)
{
	int	n;
	int	no_digit_flag;

	no_digit_flag = 0;
	n = 0;
	while (argv[n] != '\0')
	{
		if (!ft_isdigit(argv[n]) && !ft_isspace(argv[n]))
			no_digit_flag = 1;
		n++;
	}
}

int	main(int argc, char *argv[])
{
}