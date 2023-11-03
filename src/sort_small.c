/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:50:57 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:35:12 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function sorts a satck of two elements in ascending order.
 * 
 * @param a The parameter "a" is a pointer to a stack structure.
 */
void	sort2(struct s_stack *a)
{
	if (a->stack[0] > a->stack[1])
	{
		sa(a);
	}
}

/**
 * The function sorts an array of three integers.
 * 
 * @param a The parameter "a" is a pointer to a struct stack.
 * 
 * @return If the stack is already in order, the function returns without 
 * doing anything. 
 * Otherwise, the function sorts the stack in ascending order.
 */
void	sort3(struct s_stack *a)
{
	if (in_order(a->stack, 3))
		return ;
	if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2] && \
		a->stack[0] < a->stack[2])
		sa(a);
	else if (a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2] && \
		a->stack[0] > a->stack[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2] && \
		a->stack[0] > a->stack[2])
		ra(a);
	else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2] && \
		a->stack[0] < a->stack[2])
	{
		sa(a);
		ra(a);
	}
	else
		rra(a);
}

/**
 * The function finds the position of the minimum value in a given stack.
 * 
 * @param a The parameter "a" is a pointer to a struct stack, which likely 
 * contains an array of integers and information about the size of the stack.
 * The function is designed to find the position
 * of the minimum value in the stack.
 * 
 * @return The function `find_min_pos` is returning the position 
 * of the minimum value in the stack `a`.
 */
int	find_min_pos(struct s_stack *a)
{
	int	i;
	int	min;
	int	min_pos;

	min = a->stack[0];
	min_pos = 0;
	i = 0;
	while (i < a->size)
	{
		if (a->stack[i] < min)
		{
			min = a->stack[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

/**
 * The function sorts four elements in a stack by finding the minimum 
 * position, pushing it to a second stack, sorting the remaining three 
 * elements, and pushing the minimum element back to the original stack.
 * 
 * @param a The parameter "a" is a pointer to a stack data structure.
 * @param b The parameter "b" is a pointer to a stack data structure. 
 * It is likely being used as an auxiliary stack to help with sorting 
 * elements in the main stack "a".
 */
void	sort4(struct s_stack *a, struct s_stack *b)
{
	int	min_pos;

	min_pos = find_min_pos(a);
	if (min_pos < 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
		pb(a, b);
	}
	else
	{
		while (min_pos < 4)
		{
			rra(a);
			min_pos++;
		}
		pb(a, b);
	}
	sort3(a);
	pa(a, b);
}

/**
 * The function sorts five elements in a stack by finding the minimum 
 * position, pushing it to a second stack, sorting the remaining four elements 
 * using sort4, and pushing the minimum element back to the original stack.
 * 
 * @param a The parameter "a" is a pointer to a stack data structure.
 * @param b The parameter "b" is a pointer to a stack data structure.
 * It is likely being used as an auxiliary stack to help with 
 * sorting the elements in stack "a".
 */
void	sort5(struct s_stack *a, struct s_stack *b)
{
	int	min_pos;

	min_pos = find_min_pos(a);
	if (min_pos < 3)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
		pb(a, b);
	}
	else
	{
		while (min_pos < 5)
		{
			rra(a);
			min_pos++;
		}
		pb(a, b);
	}
	sort4(a, b);
	pa(a, b);
}
