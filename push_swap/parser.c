/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:50:40 by aelbouz           #+#    #+#             */
/*   Updated: 2025/04/12 09:51:44 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*remove_zero(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (ft_strdup("0"));
	result = ft_strdup(str + i);
	return (result);
}

int	trim(char *str)
{
	char	*tr;

	tr = ft_strtrim(str, " ");
	if (!tr || !str[0] || ft_strlen(tr) == 0)
		return (free(tr), 0);
	return (free(tr), 1);
}
