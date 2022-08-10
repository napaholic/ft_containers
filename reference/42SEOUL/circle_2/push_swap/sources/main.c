/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemoojung <jaemoojung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:16:18 by jaemjung          #+#    #+#             */
/*   Updated: 2022/01/22 10:37:57 by jaemoojung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	flag;

	flag = 0;
	a_to_b(a, b, (*a)->size, &flag);
}

int	main(int argc, char **argv)
{
	t_node	*node;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(1);
	node = NULL;
	check_arguments_and_append(argc, argv, &node);
	a = NULL;
	b = NULL;
	init_stacks(&node, &a, &b);
	push_swap(&a, &b);
	exit(0);
}
