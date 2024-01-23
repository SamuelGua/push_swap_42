/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:35 by scely             #+#    #+#             */
/*   Updated: 2024/01/23 17:25:43 by meca_971         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_push **pile)
{
	t_push	*temp;

	temp = *pile;
	if (temp->next == NULL)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sort_nbrs_small(t_push **pile)
{
	if ((*pile)->content > (*pile)->next->content)
		sa(pile);
	if (list_sorted(pile)!= 0 && (*pile)->content < (*pile)->next->content)
		rra(pile);
	if (list_sorted(pile) != 0)
		sa(pile);
}

// void	sort_nbrs_small_4(t_push **pile_a, t_push **pile_b)
// {
// 	int min;
// 	t_push  *temp_a;
// 	t_push	*temp_b;
	
// 	temp_a = *pile_a;
// 	temp_b = *pile_b;
// 	pb(pile_a, pile_b);
// 	sort_nbrs_small(pile_a);
// 	if (temp_b->content > min_max(pile_a, 0) || temp_b->content < min_max(pile_a, 1))
// 		pa(pile_a, pile_b);
	
// 	min = min_max(pile_a, 1);
	
// }
