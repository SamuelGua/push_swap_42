/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:11 by scely             #+#    #+#             */
/*   Updated: 2024/01/20 19:46:15 by meca_971         ###   ########.fr       */
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
	t_push	**pileA;
	t_push	**pileB;
	int		i;
	
	i = 1;
	if (ac == 1)
		return (1);
	pileA = malloc(sizeof(t_push));
	*pileA = NULL;
	pileB = malloc(sizeof(t_push));
	*pileB = NULL;
	// verifie si les ARGS sont {" 3 2 1 5" 2 8} ou {"3 2 1 5"}
	if (ft_strchr(av[1], 32) != 0 && av[2] != NULL)
		return (printf("ERROR ARGS"), -1);
	else if (ac == 2 && ft_strchr(av[1], 32) != 0)
	{
		av = ft_split(av[1], 32);
		i = 0;
	}
	// mets les ARGS dans ma pile en faisant les verife et la print (a enlever pour le push)
	if (set_pile(pileA, av, i) != 0)
		return (printf("mauvaise liste\n"),-1);
	else
		print_pile_A(*pileA, 'A');
	pb(pileA, pileB);
	pb(pileA, pileB);
	pb(pileA, pileB);
	pb(pileA, pileB);
	pb(pileA, pileB);
	
	custom(pileB);
	printf("================\n");
	print_pile_A(*pileB, 'B');
	custom(pileB);
	t_push *temp = *pileB;
	for (int i = 0; temp != NULL; temp = temp->next)
	{
		printf("content = %i | mouv = %i | sens = %i\n", temp->content, temp->mouv, temp->sens);
		i++;
	}
	temp = *pileA;
	printf("================\n");
	custom_A(pileA, pileB);
	turk_sorting(pileA, pileB);
	print_pile_A(*pileA, 'A');
	print_pile_A(*pileB, 'B');

	for (int i = 0; temp != NULL; temp = temp->next)
	{
		printf("content = %i \t|target = %i \t| cost = %i \t| mouv = %i \t| closet = %i\n", temp->content, temp->target, temp->cost, temp->mouv, temp->closet);
		i++;
	}

	
	// if (list_sorted(pileA) == 0)
	// 	return (printf("sorted"));
	// // verifie les doublons
	// if (doublons(pileA) != 0)
	// 	return (ft_putstr_fd("Error\n", 1), -1);
	// print_pile_A(*pileB, 'B');
	// //trie entre 2 et 3 elements
	// if (ac == 4)
	// 	sort_nbrs_small(pileA);
	// print_pile_A(*pileA, 'A');
	// printf("\n");
	return (0);
}
