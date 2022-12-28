/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipresno- <ipresno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:57:30 by ipresno-          #+#    #+#             */
/*   Updated: 2022/12/22 16:21:35 by ipresno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "Libft/libft.h"

# define COLOR_RED "\x1b[31m"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int	sm_rot;
	int	big_rot;
	int	sm_revrot;
	int	big_revrot;
	int	sm_flag;
	int	big_flag;
	int	min;
	int	max;
}	t_moves;

t_stack	*ft_stacknew(int value, int index);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackprev(t_stack *stack, t_stack *tail);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_freestack(t_stack **stack);
void	do_swap(t_stack *stack, char stack_name);
void	do_push(t_stack **stack1, t_stack **stack2, char stack_name);
t_stack	*do_rotate(t_stack *stack, char stack_name);
t_stack	*do_reverse_rotate(t_stack *stack, char stack_name);
void	find_moves(t_stack *stack, t_moves *moves);
int		steps_to_end(t_stack *stack, int element_index);
int		ft_init_list(int ac, char *av[], t_stack **stack);
void	stackindex(t_stack **stack, int size);
void	small_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	medium_sort(t_stack **stack_a, t_stack **stack_b, int size, int turns);
void	big_sort(t_stack **stack_a, t_stack **stack_b, int size, int turns);
void	rotate_and_push_to_a(t_stack **stack_a, t_stack **stack_b,
			t_moves *moves, int *rotates);
int		push_big_small(t_stack **stack_a, t_stack **stack_b,
			t_moves *moves, int flag);
void	find_min_max(t_stack *stack, t_moves *moves);
void	ft_print_error(int n);

#endif
