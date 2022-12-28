/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:03 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 16:27:41 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_median(t_stack **stack_a, t_stack **stack_b, int split, int half)
{
	int		flag;
	t_stack	*stack_a_aux;
	t_stack	*stack_a_end;

	stack_a_aux = *stack_a;
	stack_a_end = ft_stacklast(*stack_a);
	flag = 1;
	while (flag)
	{
		if (stack_a_aux == stack_a_end)
			flag = 0;
		if (split == 1 && stack_a_aux->index <= half)
			do_push(stack_b, stack_a, 'b');
		else if (split == 2 && stack_a_aux->index > half)
			do_push(stack_b, stack_a, 'b');
		else if (stack_a_aux->index == 0)
			flag = 0;
		else
			*stack_a = do_rotate(*stack_a, 'a');
		stack_a_aux = *stack_a;
	}
}

void	medium_sort(t_stack **stack_a, t_stack **stack_b, int size, int turns)
{
	int		rotates;
	t_moves	moves;

	rotates = 0;
	while (*stack_a)
	{
		push_median(stack_a, stack_b, turns, (size / 2) - 1);
		moves = (t_moves){0, 0, 0, 0, 0, 0, 0, 0};
		while (*stack_b)
		{
			find_min_max(*stack_b, &moves);
			find_moves(*stack_b, &moves);
			if (stack_b && (moves.sm_rot >= 0
					|| moves.sm_revrot >= 0
					|| moves.big_rot >= 0 || moves.big_revrot >= 0))
				rotates += push_big_small(stack_a, stack_b, &moves, 1);
		}
		while (--rotates)
			*stack_a = do_rotate(*stack_a, 'a');
		turns++;
		if (turns == 3)
			break ;
	}
}
