/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:42:50 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:51:44 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_idx(int *arr, int size, int nb)
{
	int	idx;
	int	i;

	i = 0;
	idx = 0;
	while (i < size)
	{
		if (arr[i] < nb)
			idx++;
		i++;
	}
	return (idx);
}

int	decrasing(t_list **stack_a, int *arr, int size)
{
	int		count;
	int		diff;
	t_list	*list;

	list = *stack_a;
	count = 0;
	while (list && list->next)
	{
		diff = calcul_idx(arr, size, list->content) - \
		calcul_idx(arr, size, list->next->content);
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		list = list->next;
	}
	if (count * 10 >= size * 3)
		return (1);
	return (0);
}

void	sort_max(t_list **stack_a, t_list **stack_b, int idx_max)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*stack_b);
	if (idx_max <= size / 2)
	{
		while (idx_max > i)
		{
			rb(stack_b);
			i++;
		}
	}
	else
	{
		while (size - idx_max > i)
		{
			rrb(stack_b);
			i++;
		}
	}
	pa(stack_a, stack_b);
}

void	find_and_sort_max(t_list **stack_a, t_list **stack_b)
{
	int		idx_max;
	int		max;
	int		i;
	t_list	*list;

	while (*stack_b)
	{
		list = *stack_b;
		max = list->content;
		i = 0;
		idx_max = 0;
		while (list)
		{
			if (list->content > max)
			{
				max = list->content;
				idx_max = i;
			}
			list = list->next;
			i++;
		}
		sort_max(stack_a, stack_b, idx_max);
	}
}

void	sort_chunk(t_list **stack_a, t_list **stack_b, int *arr, int chunk)
{
	int	idx;
	int	b_size;
	int	size;

	size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		idx = calcul_idx(arr, size, (*stack_a)->content);
		if (idx <= b_size)
			pb(stack_a, stack_b);
		else if (idx <= b_size + chunk)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if (decrasing(stack_a, arr, size))
			rra(stack_a);
		else
			ra(stack_a);
		b_size = ft_lstsize(*stack_b);
	}
	return (find_and_sort_max(stack_a, stack_b));
}
