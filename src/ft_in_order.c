/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:33:37 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:40:47 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function checks if an array of integers is in ascending order.
 * 
 * @param vec an integer array containing the elements to be 
 * checked for being in ascending order
 * @param size The size parameter is an integer that represents the 
 * size of the array or vector passed as the first argument to the function.
 * 
 * @return The function `in_order` returns an integer value of 1 if the 
 * elements in the array `vec` are in ascending order, and 0 otherwise.
 */
int	in_order(int *vec, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (vec[i] > vec[i + 1])
			return (0);
		i++;
	}
	return (1);
}
