/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:36:43 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:36:45 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(struct s_stack *a)
{
	int	val;

	val = rotate(a);
	if (val == 1)
		write (1, "ra\n", 3);
}

void	rb(struct s_stack *b)
{
	int	val;

	val = rotate(b);
	if (val == 1)
		write (1, "rb\n", 3);
}

void	rr(struct s_stack *a, struct s_stack *b)
{
	int	val1;
	int	val2;

	val1 = rotate(a);
	val2 = rotate(b);
	if (val1 == 1 && val2 == 1)
		write (1, "rr\n", 3);
}
