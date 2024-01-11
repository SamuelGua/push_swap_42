/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:46:30 by scely             #+#    #+#             */
/*   Updated: 2024/01/09 16:27:57 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push **pile_A, t_push **pile_B)
{
	t_push	*temp;

	temp = (*pile_B)->next;
	if ((*pile_B)->next == NULL)
		return ;
	(*pile_B)->next = *pile_A;
	(*pile_A) = (*pile_B);
	*pile_B = temp;
	write(1, "pa\n", 3);
}

void	pb(t_push **pile_A, t_push **pile_B)
{
	t_push	*temp;

	temp = (*pile_A)->next;
	if ((*pile_A)->next == NULL)
		return ;
	(*pile_A)->next = *pile_B;
	(*pile_B) = (*pile_A);
	*pile_A = temp;
	write(1, "pb\n", 3);
}
