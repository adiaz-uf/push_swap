/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:34:42 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:43:49 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function checks if a string contains multiple
 * numbers separated by spaces.
 * 
 * @param s The parameter `s` is a pointer to a character array
 * (string) that contains some input data.
 * This function seems to split the input string into multiple 
 * substrings using space as a delimiter and then checks if there are 
 * more than one substring. If there are more than one substring, it returns.
 * 
 * @return The function `multiple_numbers` returns an integer value.
 * If the input string `s` contains more than one number (separated by a space),
 * the function returns 1. Otherwise, it returns 0.
 */
int	multiple_numbers(char *s)
{
	char	**split;
	int		i;

	split = ft_split(s, 32);
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		i++;
	}
	if (i > 1)
		return (1);
	return (0);
}
