/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:47:41 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/05/26 11:50:37 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function `ft_free` frees the memory allocated 
 * to a two-dimensional array of strings.
 * 
 * @param a a is a pointer to a pointer of characters 
 * (i.e. a pointer to a string array or a 2D array of characters).
 * It is used to free the memory allocated to the array.
 */
void	ft_free(char **a)
{
	int	i;

	i = 0;
	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

/**
 * The function sorts a stack of integers with a size of 5 or less 
 * using different sorting algorithms based on the size of the stack.
 * 
 * @param a a is a pointer to a stack data structure.
 * @param b The parameter "b" is a pointer to a stack data structure. 
 * It is likely being used as a temporary stack to help with 
 * sorting the elements in the main stack "a".
 * 
 * @return nothing (void).
 */
void	five_or_less(struct s_stack *a, struct s_stack *b)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
	{
		sort2(a);
	}
	else if (a->size == 3)
	{
		sort3(a);
	}
	else if (a->size == 4)
	{
		sort4(a, b);
	}
	else if (a->size == 5)
	{
		sort5(a, b);
	}
	return ;
}

/**
 * The function sorts a stack using different algorithms based on its size.
 * 
 * @param a a is a pointer to a struct representing a stack.
 * It contains information about the stack such as its size and
 * the elements it contains.
 * @param b The second stack used for sorting and temporarily storing 
 * elements during the sorting process.
 * 
 * @return nothing (void).
 */
void	start(struct s_stack *a, struct s_stack *b)
{
	if (in_order(a->stack, a->size) == 1 || a->size == 1)
	{
		return ;
	}
	if (a->size <= 5)
		five_or_less(a, b);
	else if (a->size <= 100)
	{
		sort_100(a, b);
	}
	else if (a->size <= 500)
	{
		sort_500(a, b);
	}
	return ;
}

int	main(int argc, char **argv)
{
	int				i;
	int				valid;
	struct s_stack	stack_a;
	struct s_stack	stack_b;

	i = 0;
	if (argc < 2)
		return (0);
	stack_a.size = argc - 1;
	stack_b.size = 0;
	valid = parsing(argc, argv, &stack_a, &stack_b);
	if (valid == 1)
		start(&stack_a, &stack_b);
	return (0);
}
