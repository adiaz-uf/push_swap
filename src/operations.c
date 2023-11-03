/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:37:32 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/14 11:37:57 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(struct s_stack *st)
{
	int	aux;

	if (st->size <= 1)
		return (0);
	aux = st->stack[0];
	st->stack[0] = st->stack[1];
	st->stack[1] = aux;
	return (1);
}

int	push(struct s_stack *src, struct s_stack *dest)
{
	int	aux;
	int	i;

	if (src->size == 0)
		return (0);
	i = dest->size;
	if (dest->size > 0)
	{
		while (i > 0)
		{
			dest->stack[i] = dest->stack[i - 1];
			i--;
		}
	}
	dest->stack[0] = src->stack[0];
	src->size--;
	dest->size++;
	i = 0;
	while (i < src->size)
	{
		src->stack[i] = src->stack[i + 1];
		i++;
	}
	return (1);
}

int	rotate(struct s_stack *st)
{
	int	tmp;
	int	j;

	if (st->size < 2)
		return (0);
	tmp = st->stack[0];
	j = 0;
	while (st->size > j)
	{
		st->stack[j] = st->stack[j + 1];
		j++;
	}
	st->stack[st->size - 1] = tmp;
	return (1);
}

int	reverse_rotate(struct s_stack *st)
{
	int	tmp;
	int	j;

	if (st->size < 2)
		return (0);
	tmp = st->stack[st->size - 1];
	j = st->size - 1;
	while (0 < j)
	{
		st->stack[j] = st->stack[j - 1];
		j--;
	}
	st->stack[0] = tmp;
	return (1);
}
