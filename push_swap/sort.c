/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:45:11 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:51:44 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		rra(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && a > c && c > b)
		ra(stack_a);
	if (c > b && c > a && a > b)
		sa(stack_a);
	if (b > a && b > c && a > c)
		rra(stack_a);
	if (b > a && b > c && c > a)
	{
		rra(stack_a);
		sa(stack_a);
	}
	if (a > b && a > c && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min;

	size = ft_lstsize(*stack_a);
	if (size < 4 || size > 5)
		return ;
	min = find_min(*stack_a);
	push_min_to_b(stack_a, stack_b, min);
	if (size == 5)
	{
		min = find_min(*stack_a);
		push_min_to_b(stack_a, stack_b, min);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	if (size == 5)
		pa(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*sa;
	int		*arr;

	sa = *stack_a;
	arr = list_to_arr(sa);
	if (!arr)
		return ;
	if (ft_lstsize(sa) == 1)
		return ;
	if (ft_lstsize(sa) == 2)
		return (sort_two(stack_a), free (arr));
	if (ft_lstsize(sa) == 3)
		return (sort_three(stack_a), free (arr));
	if (ft_lstsize(sa) > 3 && ft_lstsize(sa) <= 5)
		return (sort_five(stack_a, stack_b), free (arr));
	if (ft_lstsize(sa) <= 100)
		return (sort_chunk(stack_a, stack_b, arr, 16), free (arr));
	if (ft_lstsize(sa) <= 500)
		return (sort_chunk(stack_a, stack_b, arr, 32), free (arr));
}
