/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:35 by scely             #+#    #+#             */
/*   Updated: 2024/01/24 18:30:31 by scely            ###   ########.fr       */
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

	if (list_sorted(pile) != 0 && (*pile)->content > (*pile)->next->content)
		sa(pile);
	if (list_sorted(pile) != 0 && (*pile)->content < (*pile)->next->content)
		rra(pile);
	if (list_sorted(pile) != 0)
		sa(pile);
}

void	sort_four(t_push **pile_a, t_push **pile_b)
{
	int		c;
	t_push	*temp_a;

	temp_a = (*pile_a);
	pb(pile_a, pile_b);
	sort_nbrs_small(pile_a);
	final_sorting(pile_a, pile_b);
	if ((*pile_b) == NULL)
	{
		(custom(pile_a), c = min_max(pile_a, 1));
		while (temp_a->content != c)
			temp_a = temp_a->next;
		if (temp_a->sens == 0)
			while (temp_a->mouv--)
				ra(pile_a);
		else
			while (temp_a->mouv--)
				rra(pile_a);
	}
}
