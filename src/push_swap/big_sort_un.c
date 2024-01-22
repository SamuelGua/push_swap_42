/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:06:17 by meca_971          #+#    #+#             */
/*   Updated: 2024/01/22 22:36:14 by meca_971         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void clear_param(t_push **pile)
{
	t_push *temp;

	temp = (*pile);
	while(temp != NULL)
	{
		temp->target = 0;
		temp->cost = 0;
		temp->mouv = 0;
		temp->closet = 0;
		temp->sens = 0;
		temp = temp->next;
	}
}

void custom(t_push **pile)
{
	int	i;
	int j;
	t_push *temp;
	
	j = 0;
	temp  = (*pile);
	i = ft_lstsize_p(*pile)/ 2;
	while ( j < i)
	{
		temp->mouv = j;
		temp->sens = 0;
		temp = temp->next;
		j++; 
	}
	if (ft_lstsize_p(*pile) % 2 != 0)
		(temp->mouv = j, temp->sens = 0, temp = temp->next);
	while (temp != NULL)
	{ 
		temp->mouv = j;
		temp->sens = 1;
		temp = temp->next;
		j--;
	}	
}
int min_max(t_push **pile, int value)
{
	t_push *temp;
	int i;

	temp = (*pile);
	i = temp->content;
	if (value == 0)
		while (temp != NULL)
		{
			if (i < temp->content)
				i = temp->content;
			temp = temp->next;
		}
	else
		while (temp != NULL)
		{
			if (i > temp->content)
				i = temp->content;
			temp = temp->next;
		}
	return (i);	
}
void	custom_a_bis(t_push  *tempA, t_push	*tempB)
{
	int	i;
	
	while (tempB != NULL)
	{
		i = tempA->content - tempB->content;
		if (i < 0)
			i *= -1;
		if (tempA->closet > i  || tempA->closet == 0)
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

void custom_A(t_push **pileA, t_push **pileB)
{
	t_push  *tempA;
	t_push	*tempB;
	int max;
	int	min;
	
	tempA = (*pileA);
	tempB = (*pileB);
	max = min_max(pileB, 0); 
	min = min_max(pileB, 1);
	custom(pileA);
	while (tempA != NULL)
	{
		if (tempA->content > max || tempA->content < min)
		{
			tempA->cost = tempA->mouv + 1;
			tempA->target = max;		
		}
		else
		{
			custom_a_bis(tempA, tempB);
			tempB = (*pileB);
		}
		tempA = tempA->next;
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
		if (tempA->content < tempB->content && tempA->closet != 0)
			rb(pileB);
	}
	else if (tempA->mouv <= tempB->mouv)
	{
		tempB->mouv -= tempA->mouv;
		while(tempA->mouv-- > 0)
			rr(pileA, pileB);
		while(tempB->mouv-- > 0)
			rb(pileB);
		if (tempA->content < tempB->content && tempA->closet != 0)
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
		if (tempA->content < tempB->content && tempA->closet != 0)
			rb(pileB);
	}
	else if (tempA->mouv <= tempB->mouv)
	{
		tempB->mouv -= tempA->mouv;
		while(tempA->mouv-- > 0)
			rrr(pileA, pileB);
		while(tempB->mouv-- > 0)
			rrb(pileB);
		if (tempA->content < tempB->content && tempA->closet != 0)
			rb(pileB);
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
	if (tempA->content < tempB->content && tempA->closet != 0)
	  	rb(pileB);
}

int	find_less_cost(t_push **pileA, t_push **pileB)
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

	i = find_less_cost(pileA, pileB);
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
	pb(pileA, pileB);
}

void	final_sorting(t_push **pileA, t_push **pileB)
{
	int	min;
	int	middle;
	int	max;
	t_push *temp_c;

	temp_c = (*pileA);
	min = (*pileA)->closet;
	middle = (*pileA)->next->content;
	max = (*pileA)->next->next->content;

}
