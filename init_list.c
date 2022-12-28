/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:19 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 15:57:20 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_validav(char *av)
{
	while (*av)
	{
		if (!ft_isdigit(*av) && *av != ' ' && *av != '-')
			return (0);
		av++;
	}
	return (1);
}

int	ft_atoi2(const char *s)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		res *= 10;
		res += (*s - '0');
		s++;
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			ft_print_error(3);
	}
	return (res * sign);
}

int	ft_sev_av(int ac, char *av[], t_stack **stack)
{
	int	i;

	i = 0;
	while (i < (ac - 1))
	{
		if (ft_validav(av[i]))
		{
			ft_stackadd_back(stack, ft_stacknew(ft_atoi2(av[i]), 0));
		}
		else
			ft_print_error(2);
		i++;
	}
	return (1);
}

int	ft_init_list(int ac, char *av[], t_stack **stack)
{
	if (ac < 2)
		ft_print_error(1);
	else if (ac == 2)
	{
		if (ft_validav(av[1]))
		{
			while (*av[1])
			{
				ft_stackadd_back(stack, ft_stacknew(ft_atoi2(av[1]), 0));
				while (*av[1] != ' ' && *av[1])
					av[1]++;
				if (*av[1])
					av[1]++;
			}
		}
		else
			ft_print_error(2);
	}
	else if (ac > 2)
	{
		av++;
		return (ft_sev_av(ac, av, stack));
	}
	return (1);
}
