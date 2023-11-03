/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:34 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/04/23 21:56:12 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function checks if a given integer is present in an array.
 * 
 * @param vec a pointer to an integer array representing the stack
 * @param num The variable "num" is an integer value that represents 
 * the number we are searching for in the array "vec".
 * @param size The parameter "size" in the function "in_stack" refers 
 * to the size of the integer array "vec". It indicates the number of 
 * elements in the array that need to be searched for the integer "num".
 * 
 * @return an integer value of either 1 or 0. If the integer "num" is
 * found in the array "vec", the function returns 1, indicating that 
 * the number is in the array. If the number is not found, the function 
 * returns 0, indicating that the number is not in the array.
 */
int	in_stack(int *vec, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (vec[i] == num)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * The function checks if a given string represents a valid integer.
 * 
 * @param num The parameter `num` is a pointer to a string that 
 * represents a number. The function `valid_int` checks if this 
 * string is a valid integer, meaning it only contains digits 
 * and an optional negative sign at the beginning.
 * 
 * @return The function `valid_int` returns an integer value 
 * of 1 if the input  string `num` represents a valid integer 
 * (i.e., contains only digits and an optional negative 
 * sign at the beginning), and 0 otherwise.
 */
int	valid(char *num)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(num);
	if (size <= 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if (num[i] == '-' && i != 0)
			return (0);
		if (!ft_isdigit(num[i]) && num[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

/**
 * The function takes in one parameter as a string, splits it into an 
 * array of strings, converts each string to an integer, and stores 
 * them in a stack if they are valid integers within the range of
 * -2147483648 to 2147483647.
 * 
 * @param argc The number of arguments passed to the function, 
 * including the name of the program itself.
 * @param argv The argv parameter is a pointer to an array of strings, 
 * where each string represents a command-line argument passed to 
 * the program. In this case, the function is expecting one 
 * argument, which is accessed through argv[1].
 * @param a a is a pointer to a struct stack, which likely 
 * contains an array of  integers and information about the 
 * size of the stack. The function one_parameter takes in a command 
 * line argument (argv[1]) and splits it into an array of strings (arr). 
 * It then converts each string to a long long
 * @param b The parameter "b" is a pointer to a struct stack.
 * 
 * @return an integer value, either 0 or 1.
 */
int	one_parameter(char **argv, struct s_stack *a, struct s_stack *b)
{
	char		**arr;
	int			i;
	long long	n;

	i = 0;
	arr = ft_split(argv[1], ' ');
	while (arr[i++] != '\0')
	{
		n = ft_atoi(arr[i - 1]);
		if ((valid(arr[i - 1]) == 1) && (in_stack(a->stack, n, i - 1) == 0) && \
			(n <= 2147483647 && n >= -2147483648))
			a->stack[i - 1] = (int)n;
		else
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit(0);
		}
	}
	a->size = i - 1;
	ft_free(arr);
	return (1);
}

/**
 * The function parses the input arguments and stores them in a stack,
 * returning 1 if successful and 0 if there is an error.
 * 
 * @param argc The number of arguments passed to the program,
 * including the name of the program itself.
 * @param argv argv is a pointer to an array of strings,
 * where each string represents a command line argument passed to the program.
 * @param a The parameter 'a' is a pointer to a struct stack,
 * which likely contains an array of integers representing a stack data 
 * structure.
 * @param b The parameter "b" is a pointer to a struct stack.
 * 
 * @return The function `parsing` returns an integer value, either 0 or 1. 
 * If the parsing is successful, it returns 1. If there is an error, it 
 * returns 0.
 */
int	parsing(int argc, char **argv, struct s_stack *a, struct s_stack *b)
{
	int			i;
	int			r;
	long long	n;

	i = 0;
	if (argc == 2)
	{
		r = one_parameter(argv, a, b);
		return (r);
	}
	if (strcmp (argv[1], "\0") == 0)
		return (0);
	while (++i < argc)
	{
		n = ft_atoi(argv[i]);
		if ((valid(argv[i]) == 1) && (in_stack(&a->stack[0], n, i - 1) == 0) && \
			(n <= 2147483647 && n >= -2147483648) && strcmp(argv[i], "-") != 0)
			a->stack[i - 1] = (int)n;
		else
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			exit(0);
		}
	}
	return (1);
}
