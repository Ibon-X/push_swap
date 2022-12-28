/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:56:59 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 17:01:32 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_quarter(t_stack **stack_a, t_stack **stack_b, int num)
{
	if (*stack_b && (*stack_b)->index > num)
		*stack_b = do_rotate(*stack_b, 'b');
	do_push(stack_b, stack_a, 'b');
}

int	ft_quarteraux(t_stack **stack_a, t_stack **stack_b, int size, int turn)
{
	if (turn == 1 && (*stack_a)->index <= size / 4)
		push_a_quarter(stack_a, stack_b, (size / 4) / 2);
	else if (turn == 2 && (*stack_a)->index > size / 4
		&& (*stack_a)->index <= size / 2)
		push_a_quarter(stack_a, stack_b, ((size / 2) / 4) * 3);
	else if (turn == 3 && (*stack_a)->index > size / 2
		&& (*stack_a)->index <= (size / 4) * 3)
		push_a_quarter(stack_a, stack_b, ((size / 2) / 4) * 5);
	else if (turn == 4 && (*stack_a)->index > (size / 4) * 3)
		push_a_quarter(stack_a, stack_b, ((size / 2) / 4) * 7);
	else if (turn == 4 && (*stack_a)->index == 0)
		return (0);
	else
		*stack_a = do_rotate(*stack_a, 'a');
	return (1);
}

void	push_quarters(t_stack **stack_a, t_stack **stack_b, int turn, int size)
{
	int		flag;
	t_stack	*stack;
	t_stack	*stack_a_end;

	stack = *stack_a;
	stack_a_end = ft_stacklast(*stack_a);
	flag = 1;
	while (flag)
	{
		if (stack == stack_a_end)
			flag = 0;
		if (ft_quarteraux(stack_a, stack_b, size, turn) == 0)
			break ;
		stack = *stack_a;
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int size, int turns)
{
	int		rotates;
	t_moves	moves;

	rotates = 0;
	while (*stack_a)
	{
		push_quarters(stack_a, stack_b, turns, size);
		moves = (t_moves){0, 0, 0, 0, 0, 0, 0, 0};
		while (*stack_b)
		{
			find_min_max(*stack_b, &moves);
			find_moves(*stack_b, &moves);
			if (stack_b && (moves.sm_rot >= 0 || moves.sm_revrot >= 0
					|| moves.big_rot >= 0 || moves.big_revrot >= 0))
				rotates += push_big_small(stack_a, stack_b, &moves, 1);
		}
		while (--rotates)
			*stack_a = do_rotate(*stack_a, 'a');
		turns++;
		if (turns == 5)
			break ;
	}
}
