/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:40:24 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:33:13 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function divides the stack 'a' into chunks of 27 elements and
 * moves them to stack 'b' based on their position in the sorted array.
 * 
 * @param a Stack a.
 * @param b Stack b.
 * @param sorted An array of integers that is already sorted in ascending order.
 * @param size The end point to be pushed to b.
 */
void	make_chunks_500(struct s_stack *a, struct s_stack *b, int *s, int size)
{
	int	start;
	int	i;
	int	tam;

	tam = 27;
	start = size - tam;
	i = start;
	while (i < size + tam)
	{
		if (in_chunck(a->stack[0], s, start, size) == 1)
		{
			pb(a, b);
			i++;
		}
		else if (in_chunck(a->stack[0], s, start + tam, size + tam) == 1)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

// Sort stack of 500 integers.
void	sort_500(struct s_stack *a, struct s_stack *b)
{
	int	*sorted;
	int	c_size;
	int	tam;

	tam = 27;
	sorted = copy_stack(a->stack, a->size);
	ft_bubblesort(sorted, a->size);
	c_size = 0;
	while (a->size > 0)
	{
		c_size = c_size + tam;
		make_chunks_500(a, b, sorted, c_size);
		c_size = c_size + tam;
	}
	b_to_a(a, b);
	free(sorted);
}
