/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:35 by scely             #+#    #+#             */
/*   Updated: 2024/01/19 09:52:49 by meca_971         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int list_sorted(t_push **pile)
{
	t_push *temp;

	temp = *pile;
	if (temp->next == NULL)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_nbrs_small(t_push **pile)
{
	if ((*pile)->content > (*pile)->next->content)
		sa(pile);
	if (list_sorted(pile) == 0 && (*pile)->content < (*pile)->next->content)
		rra(pile);
	if (list_sorted(pile) == 0)
		sa(pile);
}
