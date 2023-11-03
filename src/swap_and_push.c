/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:58:01 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/14 11:58:17 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(struct s_stack *a)
{
	int	val;

	val = swap(a);
	if (val == 1)
		write (1, "sa\n", 3);
}

void	sb(struct s_stack *b)
{
	int	val;

	val = swap(b);
	if (val == 1)
		write (1, "sb\n", 3);
}

void	ss(struct s_stack *a, struct s_stack *b)
{
	int	val1;
	int	val2;

	val1 = swap(a);
	val2 = swap(b);
	if (val1 == 1 && val2 == 1)
		write (1, "ss\n", 3);
}

void	pb(struct s_stack *a, struct s_stack *b)
{
	int	val;

	val = push(a, b);
	if (val == 1)
		write (1, "pb\n", 3);
}

void	pa(struct s_stack *a, struct s_stack *b)
{
	int	val;

	val = push(b, a);
	if (val == 1)
		write (1, "pa\n", 3);
}
