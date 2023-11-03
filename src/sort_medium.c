/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:46:21 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:32:18 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function divides the stack 'a' into chunks of
 * 16 elements and moves them to stack 'b' based on
 * their position in a sorted array.
 * 
 * @param a The first stack to be used in the function.
 * @param b The parameter "b" is a pointer to a stack data structure.
 * @param sorted An array of integers that is already sorted in ascending order.
 * @param size The end point to be pushed to b.
 */
void	make_chunks_100(struct s_stack *a, struct s_stack *b, int *s, int size)
{
	int	start;	
	int	i;
	int	tam;

	tam = 16;
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

// Sort stacks of 100 integers.
void	sort_100(struct s_stack *a, struct s_stack *b)
{
	int	*sorted;
	int	c_size;
	int	c_start;
	int	i;
	int	tam;

	sorted = copy_stack(a->stack, a->size);
	ft_bubblesort(sorted, a->size);
	tam = 16;
	c_size = 0;
	while (a->size > 0)
	{
		c_size = c_size + tam;
		make_chunks_100(a, b, sorted, c_size);
		c_size = c_size + tam;
	}
	b_to_a(a, b);
	free(sorted);
}
