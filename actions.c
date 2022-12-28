/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:09 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 16:03:59 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack *stack, char stack_name)
{
	int		vaule_aux;
	int		index_aux;
	t_stack	*second_aux;

	if (stack && stack->next)
	{
		write(1, "s", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
		vaule_aux = stack->value;
		index_aux = stack->index;
		second_aux = stack->next;
		stack->value = second_aux->value;
		stack->index = second_aux->index;
		second_aux->value = vaule_aux;
		second_aux->index = index_aux;
	}
}

void	do_push(t_stack **stack1, t_stack **stack2, char stack_name)
{
	t_stack	*elem_aux;

	if (*stack2)
	{
		write(1, "p", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
		elem_aux = (*stack2)->next;
		(*stack2)->next = *stack1;
		*stack1 = *stack2;
		*stack2 = elem_aux;
	}
}

t_stack	*do_rotate(t_stack *stack, char stack_name)
{
	t_stack	*elem_aux;
	t_stack	*elem_aux2;

	if (stack)
	{
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
		elem_aux = ft_stacklast(stack);
		elem_aux->next = stack;
		elem_aux2 = stack->next;
		stack->next = NULL;
		stack = elem_aux2;
	}
	return (stack);
}

t_stack	*do_reverse_rotate(t_stack *stack, char stack_name)
{
	t_stack	*elem_aux;

	if (stack)
	{
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
		elem_aux = ft_stacklast(stack);
		elem_aux->next = stack;
		while (stack->next != elem_aux)
			stack = stack->next;
		stack->next = NULL;
		stack = elem_aux;
	}
	return (stack);
}
