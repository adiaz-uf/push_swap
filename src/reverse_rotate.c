/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:39:17 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:39:19 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(struct s_stack *a)
{
	int	val;

	val = reverse_rotate(a);
	if (val == 1)
		write (1, "rra\n", 4);
}

void	rrb(struct s_stack *b)
{
	int	val;

	val = reverse_rotate(b);
	if (val == 1)
		write (1, "rrb\n", 4);
}

void	rrr(struct s_stack *a, struct s_stack *b)
{
	int	val1;
	int	val2;

	val1 = reverse_rotate(a);
	val2 = reverse_rotate(b);
	if (val1 == 1 && val2 == 1)
		write (1, "rrr\n", 4);
}
