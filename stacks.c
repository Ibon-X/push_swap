/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:33 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 15:57:34 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_print_error(0);
	if (new == NULL)
		return (NULL);
	else
	{
		new->value = value;
		new->index = index;
		new->next = NULL;
	}
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_stackprev(t_stack *stack, t_stack *tail)
{
	if (stack && stack != tail)
	{
		while (stack->next != tail)
			stack = stack->next;
	}
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (*stack)
	{
		tail = ft_stacklast(*stack);
		tail->next = new;
	}
	else
		*stack = new;
}

void	ft_freestack(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		aux = tmp;
		tmp = tmp->next;
		free(aux);
	}
	*stack = NULL;
}
