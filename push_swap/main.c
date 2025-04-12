/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:33:08 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:51:44 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(char **arr, int j)
{
	while (arr[j])
	{
		free(arr[j++]);
	}
	free (arr);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*list;

	list = *stack_a;
	while (list && list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d \n", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*lb;

	head = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		if (!parse_int(ft_strdup(av[1]), &head))
			return (write(2, "Error\n", 6), ft_lstclear(&head, free), 1);
	}
	else if (!parse_int(join_arr(av + 1, ac - 1), &head))
		return (write(2, "Error\n", 6), ft_lstclear(&head, free), 1);
	if (!is_dup(head))
		return (write(2, "Error\n", 6), ft_lstclear(&head, free), 1);
	if (is_sorted(&head))
		return (ft_lstclear(&head, free), 1);
	sort(&head, &lb);
	ft_lstclear(&head, free);
}
