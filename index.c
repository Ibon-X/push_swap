/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:16 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 15:57:17 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_array(int **array, t_stack *stack, int size)
{
	int	*aux;
	int	i;

	aux = *array;
	i = 0;
	while (i < size)
	{
		aux[i] = stack->value;
		stack = stack->next;
		i++;
	}
}

void	put_index(int *array, t_stack *stack)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (array[i] != stack->value)
			i++;
		stack->index = i;
		stack = stack->next;
	}
}

void	stackindex(t_stack **stack, int size)
{
	int		*array;
	int		i;
	long	aux;

	aux = 0;
	array = malloc((size + 1) * sizeof(int));
	if (!array)
		ft_print_error(0);
	create_array(&array, *stack, size);
	i = 0;
	while (i < (size - 1))
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			aux = array[i];
			array[i] = array[i + 1];
			array[i + 1] = aux;
			i = 0;
		}
	}
	put_index(array, *stack);
	free(array);
}
