/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:18:47 by aelbouz           #+#    #+#             */
/*   Updated: 2025/03/09 21:50:46 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_putunint(unsigned int nb);
int		ft_puthexa(unsigned long nb, char format);
int		ft_putptr(void *ptr);
int		ft_format(char format, va_list args);
int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
int		is_valid(char **av);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*remove_zero(char *str);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		trim(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	free_arr(char **map, int j);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		is_dup(t_list *head);
char	*join_arr(char **str, size_t size);
int		parse_int(char *str, t_list **head);
int		is_num(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	push(t_list **from, t_list **to);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list **stack_a);
int		*list_to_arr(t_list *stack_a);
void	sort(t_list **stack_a, t_list **stack_b);
void	push_min_to_b(t_list **stack_a, t_list **stack_b, int min);
int		find_min(t_list *stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_chunk(t_list **stack_a, t_list **stack_b, int *arr, int chunk);
int		is_sorted(t_list **stack_a);
int		calcul_idx(int *arr, int size, int nb);
void	sort_max(t_list **stack_a, t_list **stack_b, int idx_max);
void	find_and_sort_max(t_list **stack_a, t_list **stack_b);

#endif