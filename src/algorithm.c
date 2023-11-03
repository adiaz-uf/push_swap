/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:32:34 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:42:38 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function moves all elements from stack b to stack a while
 * keeping the minimum number of operations.
 * 
 * @param a The parameter "a" is a pointer to a stack structure.
 * @param b The parameter "b" is a pointer to a stack data structure.
 */
void	b_to_a(struct s_stack *a, struct s_stack *b)
{
	int	max;

	while (b->size > 0)
	{
		max = find_max_pos(b);
		if (max < ((b->size) - 1) / 2)
		{
			while (max-- != 0)
				rb(b);
			pa(a, b);
		}
		else
		{
			while (max++ < b->size)
				rrb(b);
			pa(a, b);
		}
	}
}

/**
 * The function copies an integer array (stack) of a given 
 * size and returns a pointer to the copy.
 * 
 * @param stack The stack to be copied.
 * @param size The size of the array to be copied.
 * 
 * @return the copy of the stack.
 */
int	*copy_stack(int *stack, int size)
{
	int	*copy;
	int	i;

	i = 0;
	copy = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		copy[i] = stack[i];
		i++;
	}
	return (copy);
}

/**
 * The function implements the bubble sort algorithm to 
 * sort an array of integers in ascending order.
 * 
 * @param a The parameter "a" is a pointer to an integer 
 * array, which represents the array to be sorted
 * using the bubble sort algorithm.
 * @param size The size parameter in the function ft_bubblesort 
 * is an integer that represents the size
 * of the array that needs to be sorted.
 * 
 * @return The function `ft_bubblesort` returns a pointer to 
 * the sorted array of integers.
 */
int	*ft_bubblesort(int *a, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (a[j] > a[j + 1])
			{
				aux = a[j];
				a[j] = a[j + 1];
				a[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
	return (a);
}

/**
 * The function checks if a given number is present 
 * in a chunk of integers.
 * 
 * @param num The integer value that we are checking 
 * for in the chunk array.
 * @param chunk A pointer to an integer array 
 * sorted in ascending order.
 * @param c_start_size The starting index of the chunk 
 * array where the function should begin searching
 * for the given number.
 * @param c_end_size c_end_size is the size of the chunk array.
 * It represents the index of the last
 * element in the chunk array plus one.
 * 
 * @return an integer value, either 1 or 0. If the input integer `num` 
 * is found in the array `chunk` between the indices `c_start_size` 
 * and `c_end_size`, the function returns 1. Otherwise, it returns 0.
 */
int	in_chunck(int num, int *chunk, int c_start_size, int c_end_size)
{
	while (c_start_size < c_end_size)
	{
		if (chunk[c_start_size] == num)
			return (1);
		c_start_size++;
	}
	return (0);
}

/**
 * The function finds the position of the maximum value in a stack.
 * 
 * @param st The parameter `st` is a pointer to a `struct stack`,
 * which is a user-defined data structure that represents a stack. 
 * The function `find_max_pos` takes this stack as input and returns
 * the position of the maximum element in the stack.
 * 
 * @return The function `find_max_pos` is returning an integer 
 * value which represents the position of the maximum element in the stack.
 */
int	find_max_pos(struct s_stack *st)
{
	int	i;
	int	max;
	int	max_pos;

	max = st->stack[0];
	max_pos = 0;
	i = 0;
	while (i < st->size)
	{
		if (st->stack[i] > max)
		{
			max = st->stack[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}
