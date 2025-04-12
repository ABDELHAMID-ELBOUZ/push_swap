/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:04:13 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:51:44 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	if (i > 1)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
		num++;
	}
	if (num == 0)
		return (0);
	return (1);
}

char	*join_arr(char **str, size_t size)
{
	size_t	i;
	char	*temp;
	char	*result;

	if (!str || !trim(str[0]))
		return (NULL);
	i = 0;
	temp = NULL;
	result = ft_strdup(str[0]);
	if (!result)
		return (NULL);
	while (++i < size)
	{
		if (!trim(str[i]))
			return (free(result), NULL);
		temp = ft_strjoin(result, " ");
		if (!temp)
			return (free(result), NULL);
		free (result);
		result = ft_strjoin(temp, str[i]);
		if (!result)
			return (free(temp), NULL);
		free(temp);
	}
	return (result);
}

int	is_num(char *str)
{
	int		nb;
	char	*cp_str;

	if (!check_num(str))
		return (0);
	nb = ft_atoi(str);
	cp_str = remove_zero(str);
	if (!cp_str)
		return (0);
	if ((nb == 0 || nb == -1) && ft_strlen(str) > 2)
		return (free(cp_str), 0);
	return (free(cp_str), 1);
}

int	is_dup(t_list *head)
{
	t_list	*node;

	node = head->next;
	while (head)
	{
		while (node)
		{
			if (head->content == node->content)
				return (0);
			node = node->next;
		}
		head = head->next;
		if (head)
			node = head->next;
	}
	return (1);
}

int	parse_int(char *str, t_list **head)
{
	int		i;
	char	**num;

	if (!str || !str[0])
		return (free(str), 0);
	num = ft_split(str, ' ');
	i = 0;
	while (num[i])
	{
		if (!is_num(num[i]))
			return (free_arr(num, 0), free(str), 0);
		ft_lstadd_back(head, ft_lstnew(ft_atoi(num[i])));
		i++;
	}
	if (i == 0)
		return (free_arr(num, 0), free(str), 0);
	return (free_arr(num, 0), free(str), 1);
}
