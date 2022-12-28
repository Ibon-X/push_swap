/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:06 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 15:57:07 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	order_two(t_stack **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		do_swap(*stack, 'a');
}

void	order_three(t_stack **stack, int size)
{
	int	big_revrotate;

	big_revrotate = steps_to_end(*stack, size - 1);
	if (big_revrotate >= 1)
		while (big_revrotate-- > 1)
			*stack = do_reverse_rotate(*stack, 'a');
	order_two(stack);
}

void	order_four(t_stack **stack_a, t_stack **stack_b, int size)
{
	while ((*stack_a)->index != 0)
		*stack_a = do_rotate(*stack_a, 'a');
	do_push(stack_b, stack_a, 'b');
	order_three(stack_a, size);
	do_push(stack_a, stack_b, 'a');
}

void	order_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		end;
	t_stack	*aux;
	t_stack	*stack_a_end;

	end = 0;
	stack_a_end = ft_stacklast(*stack_a);
	while (end != 1)
	{
		if (*stack_a == stack_a_end)
			end = 1;
		if ((*stack_a)->index < 2)
			do_push(stack_b, stack_a, 'b');
		else
			*stack_a = do_rotate(*stack_a, 'a');
	}
	order_three(stack_a, size);
	aux = (*stack_b)->next;
	if ((*stack_b)->index < aux->index)
		do_swap(*stack_b, 'b');
	do_push(stack_a, stack_b, 'a');
	do_push(stack_a, stack_b, 'a');
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		order_two(stack_a);
	else if (size == 3)
		order_three(stack_a, size);
	else if (size == 4)
		order_four(stack_a, stack_b, size);
	else if (size == 5)
		order_five(stack_a, stack_b, size);
}
