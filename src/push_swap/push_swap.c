/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:11 by scely             #+#    #+#             */
/*   Updated: 2024/01/11 11:54:03 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile_A(t_push *set_pile_A, char pile)
{
	t_push	*current = set_pile_A;
	printf("%c | ", pile);
	while (current != NULL)
	{
		printf("%d ", current->content);
		current = current->next;
	}
	printf("\n");
}

void print_sort(int i)
{
	if (i == 0)
		printf("pas triee %s\n\n", "\U0001f975");
	else
		printf("Triee %s\n\n", "\U0001f600");
}
int main(int ac, char **av)
{
	t_push **pileA;
	t_push **pileB;
	
	if (ac == 1)
		return (1);
	pileA = malloc(sizeof(t_push));
	*pileA = NULL;
	pileB = malloc(sizeof(t_push));
	*pileB = NULL;
	set_pile(pileA, av);

	for (int x = 0; av[x] != NULL; x++)
		printf("%s ", av[x]);
	printf("\n");
	print_pile_A(*pileA, 'A');
	print_pile_A(*pileB, 'B');
	// if (list_sorted(pileA) == 0)
	//  		return (print_sort(list_sorted(pileA)), 1);
	if (ac - 1 < 5)
		sort_nbrs_small(pileA);
	int i = 1;
	while (av[i])
	{
			if (check_numbers(av[i]) != 0)
				return (printf("mauvaise liste\n\n"));
			i++;
	}
	// if (av[i])
	// 	return (printf("pas bon"));
	if (doublons(pileA) != 0)
		return(printf("doublon\n\n"));
	else
		return(printf("c'est bon\n\n"));
	// print_pile_A(*pileA, 'A');
	// print_pile_A(*pileB, 'B');
	// print_sort(list_sorted(pileA));

	printf("\n\n");
	return (0);
}
