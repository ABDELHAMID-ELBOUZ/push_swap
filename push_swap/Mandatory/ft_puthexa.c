/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:02:48 by aelbouz           #+#    #+#             */
/*   Updated: 2025/02/22 16:53:23 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_puthexa(unsigned long nb, char format)
{
	int		i;
	char	*base;

	i = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb >= 16)
		i += ft_puthexa(nb / 16, format);
	i += ft_putchar(base[nb % 16]);
	return (i);
}
