/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:11 by scely             #+#    #+#             */
/*   Updated: 2024/01/23 22:32:27 by meca_971         ###   ########.fr       */
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
	if (i == 1)
		printf("pas triee %s\n\n", "\U0001f975");
	else
		printf("Triee %s\n\n", "\U0001f600");
}

void push_swap(t_push  **pile_a, t_push **pile_b)
{
	if (ft_lstsize_p(*pile_a) == 2)
		(sa(pile_a));
	else if (ft_lstsize_p(*pile_a) == 3)
		sort_nbrs_small(pile_a);
	else if (ft_lstsize_p(*pile_a) == 5)
		return ;
	else if (ft_lstsize_p(*pile_a) > 5)
		all_insruction(pile_a, pile_b);
}
int main(int ac, char **av)
{
	t_push	**pileA;
	t_push	**pileB;
	int		i;
	
	i = 1;
	if ( ac == 1 || (ft_strchr(av[1], 32) != 0 && av[2] != NULL))
		return (ft_putstr_fd("Error\n", 2), 1);
	pileA = malloc(sizeof(t_push));
	pileB = malloc(sizeof(t_push));
 	if (ac == 2 && ft_strchr(av[1], 32) != 0)
	{
		av = ft_split(av[1], 32);
		i = 0;
	}
	if (set_pile(pileA, av, i) != 0 || doublons(pileA) != 0 )
		return (ft_putstr_fd("Error\n", 2), 1);
	if (list_sorted(pileA) == 0)
		return(0);
	//(print_pile_A(*pileA, 'A'), print_pile_A(*pileB, 'B'));
	push_swap(pileA, pileB);
	//if (i == 0)
	//	ft_free(av);
	// clear_pile(pileA, pileB)
	//printf("---------------------\n");
	(print_pile_A(*pileA, 'A'), print_pile_A(*pileB, 'B'));
	print_sort(list_sorted(pileA));
	return (0);
}
