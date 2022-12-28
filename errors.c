/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:13 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 16:01:16 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(int n)
{
	if (n == 0)
		ft_putstr_fd(COLOR_RED "Error\n", 2);
	else if (n == 1)
		ft_putstr_fd(COLOR_RED "Error: few inputs\n", 2);
	else if (n == 2)
		ft_putstr_fd(COLOR_RED "Error: invalid inputs\n", 2);
	else if (n == 3)
		ft_putstr_fd(COLOR_RED "Error: too large inputs\n", 2);
	else if (n == 4)
		ft_putstr_fd(COLOR_RED "Error: duplicated inputs\n", 2);
	exit(0);
}
