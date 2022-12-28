/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:22 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 16:17:00 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *stack)
{
	int		size;
	t_stack	*aux;

	size = 0;
	while (stack->next)
	{
		aux = stack->next;
		while (aux)
		{
			if (stack->value == aux->value)
				ft_print_error(4);
			aux = aux->next;
		}
		stack = stack->next;
		size++;
	}
	size++;
	return (size);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*aux;

	aux = stack->next;
	while (aux)
	{
		if (stack->value > aux->value)
			return (0);
		stack = stack->next;
		aux = aux->next;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_init_list(ac, av, &stack_a))
	{
		if (stack_a && stack_a->next)
		{
			size = check_duplicates(stack_a);
			if (size > 1 && !(is_sorted(stack_a)))
			{
				stackindex(&stack_a, size);
				if (size <= 5)
					small_sort(&stack_a, &stack_b, size);
				else if (size <= 100)
					medium_sort(&stack_a, &stack_b, size, 1);
				else if (size > 100)
					big_sort(&stack_a, &stack_b, size, 1);
			}
		}
	}
	ft_freestack(&stack_a);
	return (0);
}
