/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:39:24 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:51:44 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_to_arr(t_list *stack_a)
{
	int		*arr;
	t_list	*la;
	int		i;

	arr = malloc(ft_lstsize(stack_a) * sizeof(int));
	if (!arr)
		return (NULL);
	la = stack_a;
	i = 0;
	while (la)
	{
		arr[i] = la->content;
		la = la->next;
		i++;
	}
	return (arr);
}

int	find_min(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	push_min_to_b(t_list **stack_a, t_list **stack_b, int min)
{
	t_list	*tmp;
	int		pos;
	int		size;

	pos = 0;
	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	while (tmp && tmp->content != min)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= size / 2)
	{
		while ((*stack_a)->content != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->content != min)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}
