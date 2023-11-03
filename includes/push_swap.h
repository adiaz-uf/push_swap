/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:16:39 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/05/26 12:15:46 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

struct s_stack
{
	int	stack[600];
	int	size;
};

int		swap(struct s_stack *st);
void	sa(struct s_stack *a);
void	sb(struct s_stack *b);
void	ss(struct s_stack *a, struct s_stack *b);

int		push(struct s_stack *src, struct s_stack *dest);
void	pb(struct s_stack *a, struct s_stack *b);
void	pa(struct s_stack *a, struct s_stack *b);

int		rotate(struct s_stack *st);
void	ra(struct s_stack *a);
void	rb(struct s_stack *b);
void	rr(struct s_stack *a, struct s_stack *b);

int		reverse_rotate(struct s_stack *st);
void	rra(struct s_stack *a);
void	rrb(struct s_stack *b);
void	rrr(struct s_stack *a, struct s_stack *b);

void	start(struct s_stack *a, struct s_stack *b);
void	five_or_less(struct s_stack *a, struct s_stack *b);
void	ft_free(char **a);

void	sort2(struct s_stack *a);
void	sort3(struct s_stack *a);
void	sort4(struct s_stack *a, struct s_stack *b);
void	sort5(struct s_stack *a, struct s_stack *b);
void	sort_100(struct s_stack *a, struct s_stack *b);
void	sort_500(struct s_stack *a, struct s_stack *b);

void	b_to_a(struct s_stack *a, struct s_stack *b);
int		find_min_pos(struct s_stack *a);
int		find_max_pos(struct s_stack *st);
int		in_order(int *vec, int size);
int		*copy_stack(int *stack, int size);
int		*ft_bubblesort(int *a, int size);
int		in_chunck(int num, int *chunk, int c_start_size, int c_end_size);

int		parsing(int argc, char **argv, struct s_stack *a, struct s_stack *b);
int		one_parameter(char **ar, struct s_stack *a, struct s_stack *b);
int		in_stack(int *vec, int num, int size);
int		multiple_numbers(char *s);
int		ft_isValidInteger(char *num);

#endif
