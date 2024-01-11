/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:49:02 by scely             #+#    #+#             */
/*   Updated: 2024/01/09 16:23:54 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push **pile_A)
{
	t_push	*temp;
	t_push	*lst;

	if ((*pile_A)->next == NULL)
		return ;
	temp = (*pile_A);
	while ((*pile_A)->next != NULL)
	{
		lst = (*pile_A);
		(*pile_A) = (*pile_A)->next;
	}
	lst->next = NULL;
	(*pile_A)->next = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_push **pile_b)
{
	t_push	*temp;
	t_push	*lst;

	if ((*pile_b)->next == NULL)
		return ;
	temp = (*pile_b);
	while ((*pile_b)->next != NULL)
	{
		lst = (*pile_b);
		(*pile_b) = (*pile_b)->next;
	}
	lst->next = NULL;
	(*pile_b)->next = temp;
	write(1, "rra\n", 4);
}

void	rrr(t_push **pile_A, t_push **pile_B)
{
	ra(pile_A);
	rb(pile_B);
}
