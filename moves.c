/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:27 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 16:25:07 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_to_start(t_stack *stack, int element_index)
{
	int		steps;
	t_stack	*aux;

	steps = 0;
	if (stack)
	{
		aux = stack;
		while (aux->index != element_index)
		{
			steps++;
			aux = aux->next;
		}
	}
	return (steps);
}

int	steps_to_end(t_stack *stack, int element_index)
{
	int		steps;
	t_stack	*aux;

	steps = 0;
	if (stack)
	{
		aux = ft_stacklast(stack);
		while (aux->index != element_index)
		{
			steps++;
			aux = ft_stackprev(stack, aux);
		}
		steps++;
	}
	return (steps);
}

void	moves_smallest(t_stack *stack, t_moves **moves)
{
	if (stack)
	{
		(*moves)->sm_rot = steps_to_start(stack, (*moves)->min);
		(*moves)->sm_revrot = steps_to_end(stack, (*moves)->min);
		if ((*moves)->sm_rot <= (*moves)->sm_revrot)
			(*moves)->sm_revrot = -1;
		else
			(*moves)->sm_rot = -1;
	}
}

void	moves_biggest(t_stack *stack, t_moves	**moves)
{
	if (stack)
	{
		(*moves)->big_rot = steps_to_start(stack, (*moves)->max);
		(*moves)->big_revrot = steps_to_end(stack, (*moves)->max);
		if ((*moves)->big_rot <= (*moves)->big_revrot)
			(*moves)->big_revrot = -1;
		else
			(*moves)->big_rot = -1;
	}
}

void	find_moves(t_stack *stack, t_moves *moves)
{
	moves_smallest(stack, &moves);
	moves_biggest(stack, &moves);
	if (moves->big_rot != -1 && (moves->big_rot >= moves->sm_rot
			&& moves->big_rot >= moves->sm_revrot))
		moves->big_rot = -1;
	else if (moves->big_revrot != -1
		&& (moves->big_revrot >= moves->sm_rot
			&& moves->big_revrot >= moves->sm_revrot))
		moves->big_revrot = -1;
	else if (moves->sm_rot != -1
		&& (moves->sm_rot >= moves->big_rot
			&& moves->sm_rot >= moves->big_revrot))
		moves->sm_rot = -1;
	else if (moves->sm_revrot != -1
		&& (moves->sm_revrot >= moves->big_rot
			&& moves->sm_revrot >= moves->big_revrot))
		moves->sm_revrot = -1;
	if (moves->sm_rot != -1 || moves->sm_revrot != -1)
		moves->sm_flag = 1;
	else if (moves->big_rot != -1 || moves->big_revrot != -1)
		moves->big_flag = 1;
}
