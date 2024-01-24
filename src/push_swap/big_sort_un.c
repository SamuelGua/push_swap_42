/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:06:17 by meca_971          #+#    #+#             */
/*   Updated: 2024/01/24 13:58:13 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_param(t_push **pile)
{
	t_push	*temp;

	temp = (*pile);
	while (temp != NULL)
	{
		temp->target = 0;
		temp->cost = 0;
		temp->mouv = 0;
		temp->closet = 0;
		temp->sens = 0;
		temp = temp->next;
	}
}

void	custom(t_push **pile)
{
	int		j;
	t_push	*temp;

	j = 0;
	temp = (*pile);
	while (j < (ft_lstsize_p(*pile) / 2))
	{
		temp->mouv = j;
		temp->sens = 0;
		temp = temp->next;
		j++;
	}
	if (ft_lstsize_p(*pile) % 2 != 0)
	{
		temp->mouv = j;
		temp->sens = 0;
		temp = temp->next;
	}
	while (temp != NULL)
	{
		temp->mouv = j;
		temp->sens = 1;
		temp = temp->next;
		j--;
	}	
}

int	min_max(t_push **pile, int value)
{
	t_push	*temp;
	int		i;

	temp = (*pile);
	i = temp->content;
	if (value == 0)
	{
		while (temp != NULL)
		{
			if (i < temp->content)
				i = temp->content;
			temp = temp->next;
		}
	}
	else
	{
		while (temp != NULL)
		{
			if (i > temp->content)
				i = temp->content;
			temp = temp->next;
		}
	}
	return (i);
}

void	custom_a_bis_zero(t_push *tempA, t_push *tempB, int max)
{
	while (tempB->content != max)
		tempB = tempB->next;
	if (tempA->sens == tempB->sens)
	{
		if (tempA->mouv > tempB->mouv)
			tempA->cost = tempA->mouv + 1;
		else
			tempA->cost = tempB->mouv + 1;
	}
	else
		tempA->cost = tempA->mouv + tempB->mouv + 1;
	tempA->target = max;
}

void	custom_a_bis_un(t_push *tempA, t_push	*tempB)
{
	int	i;

	while (tempB != NULL)
	{
		i = tempA->content - tempB->content;
		if (i < 0)
			i *= -1;
		if (tempA->closet > i || tempA->closet == 0)
		{
			tempA->closet = i;
			tempA->target = tempB->content;
			if (tempA->sens == tempB->sens)
			{
				if (tempA->mouv >= tempB->mouv)
					tempA->cost = tempA->mouv +1;
				else
					tempA->cost = tempB->mouv +1;
			}
			else
				tempA->cost = tempA->mouv + tempB->mouv +1;
		}
		tempB = tempB->next;
	}	
}

void	custom_a(t_push **pile_a, t_push **pile_b)
{
	t_push	*tempa;
	t_push	*tempb;
	int		max;
	int		min;

	tempa = (*pile_a);
	custom(pile_a);
	custom(pile_b);
	while (tempa != NULL)
	{
		max = min_max(pile_b, 0);
		min = min_max(pile_b, 1);
		tempb = (*pile_b);
		if (tempa->content > max || tempa->content < min)
			custom_a_bis_zero(tempa, tempb, max);
		else
			custom_a_bis_un(tempa, tempb);
		tempa = tempa->next;
	}	
}

void	mouv_sens_zero(t_push *tempA, t_push *tempB, t_push **pileA, t_push **pileB)
{
	if (tempA->mouv >= tempB->mouv)
	{
		tempA->mouv -= tempB->mouv;
		while(tempB->mouv-- > 0)
			rr(pileA, pileB);
		while(tempA->mouv-- > 0)
			ra(pileA);
	}
	else if (tempA->mouv <= tempB->mouv)
	{
		tempB->mouv -= tempA->mouv;
		while(tempA->mouv-- > 0)
			rr(pileA, pileB);
		while(tempB->mouv-- > 0)
			rb(pileB);
	}
}

void	mouv_sens_un(t_push *tempA, t_push *tempB, t_push **pileA, t_push **pileB)
{
	if (tempA->mouv >= tempB->mouv)
	{
		tempA->mouv -= tempB->mouv;
		while(tempB->mouv-- > 0)
			rrr(pileA, pileB);
		while(tempA->mouv-- > 0)
			rra(pileA);
	}
	else if (tempA->mouv <= tempB->mouv)
	{
		tempB->mouv -= tempA->mouv;
		while(tempA->mouv-- > 0)
			rrr(pileA, pileB);
		while(tempB->mouv-- > 0)
			rrb(pileB);
	}	
}

void	mouv_opposite(t_push *tempA, t_push *tempB, t_push **pileA, t_push **pileB)
{
	if (tempA->sens == 0)
		while (tempA->mouv-- > 0)
			ra(pileA);
	else 
		while (tempA->mouv-- > 0)
			rra(pileA);
	if (tempB->sens == 0)
		while (tempB->mouv-- > 0)
			rb(pileB);
	else 
		while (tempB->mouv-- > 0)
			rrb(pileB);
}

int	find_less_cost(t_push **pileA)
{
	t_push *tempA;
	t_push *tempB;
	int 	j;
	int		i;

	tempA = (*pileA);
	i = tempA->content;
	j = tempA->cost;
	while (tempA != NULL)
	{
		tempB = tempA->next;
		while (tempB != NULL)
		{
			if (tempA->cost < j)
			{
				i = tempA->content;
				j = tempA->cost;
			}
			tempB = tempB->next;
		}
		tempA = tempA->next;
	}
	return (i);
}

void	turk_sorting(t_push **pileA, t_push **pileB)
{
	t_push *tempA;
	t_push *tempB;
	int 	i;

	i = find_less_cost(pileA);
	tempA = (*pileA);
	tempB = (*pileB);
	while (tempA->content != i)
		tempA = tempA->next;
	while(tempA->target != tempB->content && tempB != NULL)	
		tempB = tempB->next;
	if (tempA->sens == tempB->sens && tempA->sens == 0)
		mouv_sens_zero(tempA, tempB, pileA, pileB);
	else if (tempA->sens == tempB->sens && tempA->sens == 1)
		mouv_sens_un(tempA, tempB, pileA, pileB);
	else if (tempA->sens != tempB->sens)
		mouv_opposite(tempA, tempB, pileA, pileB);
	if (tempA->content < tempB->content && tempA->closet != 0)
		rb(pileB);
	pb(pileA, pileB);
}

void	final_sorting(t_push **pileA, t_push **pileB)
{
	int	i;
	t_push	*temp_a = (*pileA);
	t_push	*temp_b = (*pileB);

	custom(pileA);
	custom(pileB);

	if  (temp_b->content > min_max(pileA, 0))
		temp_b->target = min_max(pileA, 0);
	else if (temp_b->content < min_max(pileA, 1))
		temp_b->target = min_max(pileA, 1);
	else
	{
		while (temp_a != NULL)
		{
			i = temp_b->content - temp_a->content;
			if (i < 0)
				i *= -1;
			if (temp_b->closet > i  || temp_b->closet == 0)
			{
				temp_b->closet = i;
				temp_b->target = temp_a->content;
			}
			temp_a = temp_a->next;
		}
	}
	temp_a = (*pileA);
	while (temp_a->content != temp_b->target)
		temp_a = temp_a->next;
	if (temp_a->sens == temp_b->sens && temp_a->sens == 0)
		mouv_sens_zero(temp_a, temp_b, pileA, pileB);
	else if (temp_a->sens == temp_b->sens && temp_a->sens == 1)
		mouv_sens_un(temp_a, temp_b, pileA, pileB);
	else if (temp_a->sens != temp_b->sens)
		mouv_opposite(temp_a, temp_b, pileA, pileB);
	 if  (temp_b->content > min_max(pileA, 1))
	{
		if (temp_a->content < temp_b->content)
	 		ra(pileA);
	}
	pa(pileA, pileB);
}

void  all_insruction(t_push **pile_a, t_push **pile_b)
{
	t_push *temp_a;
	
	(pb(pile_a, pile_b), pb(pile_a, pile_b));
	while (ft_lstsize_p(*pile_a) > 3)
	{
		custom_a(pile_a, pile_b);
		turk_sorting(pile_a, pile_b);
		clear_param(pile_a);
		clear_param(pile_b);
	}
	temp_a = (*pile_a);
	sort_nbrs_small(pile_a);
	while (ft_lstsize_p((*pile_b)))
		final_sorting(pile_a, pile_b);
	temp_a = (*pile_a);
	if( (*pile_b) == NULL)
	{
		custom(pile_a);
		int c = min_max(pile_a, 1);
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
