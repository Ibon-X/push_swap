/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:56:56 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 16:27:10 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_and_push_to_a(t_stack **stack_a, t_stack **stack_b,
	t_moves *moves, int *rotates)
{
	if (moves->sm_rot >= 0)
		while (moves->sm_rot--)
			*stack_b = do_rotate(*stack_b, 'b');
	else if (moves->sm_revrot >= 0)
		while (moves->sm_revrot--)
			*stack_b = do_reverse_rotate(*stack_b, 'b');
	else if (moves->big_rot >= 0)
		while (moves->big_rot--)
			*stack_b = do_rotate(*stack_b, 'b');
	else if (moves->big_revrot >= 0)
		while (moves->big_revrot--)
			*stack_b = do_reverse_rotate(*stack_b, 'b');
	do_push(stack_a, stack_b, 'a');
	if (moves->sm_flag)
		*stack_a = do_rotate(*stack_a, 'a');
	if (moves->big_flag || !*stack_b)
		(*rotates)++;
	*moves = (t_moves){0, 0, 0, 0, 0, 0, 0, 0};
}

int	push_big_small(t_stack **stack_a,
		t_stack **stack_b, t_moves *moves, int flag)
{
	int		rotates;
	t_stack	*stack_a_aux;
	t_stack	*stack_b_tail;

	stack_a_aux = *stack_b;
	stack_b_tail = ft_stacklast(*stack_b);
	rotates = 0;
	while (flag)
	{		
		while (stack_a_aux->index != moves->min
			&& stack_a_aux->index != moves->max)
			stack_a_aux = stack_a_aux->next;
		if (stack_a_aux->index == moves->min
			|| stack_a_aux->index == moves->max)
		{
			rotate_and_push_to_a(stack_a, stack_b, moves, &rotates);
			flag = 0;
		}
		else
			stack_a_aux = stack_a_aux->next;
		if (stack_a_aux == stack_b_tail)
			flag = 0;
		stack_a_aux = *stack_b;
	}
	return (rotates);
}

void	find_min_max(t_stack *stack, t_moves *moves)
{
	t_stack		*aux;
	t_stack		*tail;

	aux = stack;
	tail = ft_stacklast(stack);
	moves->min = stack->index;
	moves->max = stack->index;
	while (1)
	{
		if (aux->index <= moves->min)
			moves->min = aux->index;
		if (aux->index > moves->max)
			moves->max = aux->index;
		if (aux == tail)
			break ;
		aux = aux->next;
	}
}
