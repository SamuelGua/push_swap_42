/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:11 by scely             #+#    #+#             */
/*   Updated: 2024/01/22 22:36:30 by meca_971         ###   ########.fr       */
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

	(print_pile_A(*pileA, 'A'), print_pile_A(*pileB, 'B'));
	printf("---------------------\n");

	pb(pileA, pileB);
	pb(pileA, pileB);
	(print_pile_A(*pileA, 'A'), print_pile_A(*pileB, 'B'));
	
	int a = ft_lstsize_p(*pileA);
	t_push *temp2 = (*pileA);

	while (a > 3)
	{
		printf("---------------------- v\t%i\n", a);
		custom(pileB);
		custom_A(pileA, pileB);
		for (int i = 0; temp2 != NULL; temp2 = temp2->next)
		{
		printf("content = %i \t|target = %i \t| cost = %i \t| mouv = %i \t| closet = %i\t| sens = %i\n", temp2->content, temp2->target, temp2->cost, temp2->mouv, temp2->closet, temp2->sens);
		i++;
		}
			temp2 = (*pileB);
		printf("++++++++++++++++++++++++++++++++++\n");
		for (int i = 0; temp2 != NULL; temp2 = temp2->next)
		{
		printf("content = %i \t|target = %i \t| cost = %i \t| mouv = %i \t| closet = %i \t| sens = %i\n", temp2->content, temp2->target, temp2->cost, temp2->mouv, temp2->closet, temp2->sens);
		i++;
		}
		turk_sorting(pileA, pileB);
		(print_pile_A(*pileA, 'A'), print_pile_A(*pileB, 'B'));
		clear_param(pileA);
		clear_param(pileB);
		a--;
	temp2 = (*pileA);

	}
	sort_nbrs_small(pileA);
	//final_sorting(pileA, pileB);
	printf("---------------------\n");

	print_pile_A(*pileA, 'A');
	print_pile_A(*pileB, 'B');
	return (0);
}
