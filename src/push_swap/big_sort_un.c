/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:06:17 by meca_971          #+#    #+#             */
/*   Updated: 2024/01/21 15:18:22 by meca_971         ###   ########.fr       */
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
	
	// mouv et sens
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

void custom_A(t_push **pileA, t_push **pileB)
{
	int i;
	t_push  *tempA = (*pileA);
	t_push	*tempB = (*pileB);
	int max;
	int	min;
	
	max = min_max(pileB, 0); 
	min = min_max(pileB, 1);
	custom(pileA);
	while (tempA != NULL)
	{
		// cherhe si le content du noeud  actuelle est le plus plus  grand ou
		// plus petit nombre de la pile b
		if (tempA->content > max || tempA->content < min)
			{
				tempA->cost = tempA->mouv + 1;
				tempA->target = max;
			}
		else
		{
			// target pas bon 
			while (tempB != NULL)
			{
				i = tempA->content - tempB->content;
				if (i < 0)
					i *= -1;
				//printf("^%i^\n", tempA->closet);
				//printf("%i\t<%i>\t%i\n",tempA->content, i, tempB->content);
				if (tempA->closet > i  || tempA->closet == 0)
				{
					tempA->closet = i;
					tempA->target = tempB->content;
					if (tempA->sens == tempB->sens)
					{
						if (tempA->mouv + 1 >= tempB->mouv)
							tempA->cost = tempA->mouv +1;
						else
							tempA->cost = tempB->mouv +1;
					}
					else
						tempA->cost = tempA->mouv + tempB->mouv +1;
				}
				tempB = tempB->next;
			}
			tempB = (*pileB);
		}
		//printf("------------------\n");
		tempA = tempA->next;
	}	
}

void	turk_sorting(t_push **pileA, t_push **pileB)
{
	t_push *tempA;
	t_push *tempB;
	int i;

	tempA = (*pileA);
	tempB = (*pileA)->next;
	while (tempB != NULL)
	{
		if (tempA->cost < tempB->cost)
			i = tempA->content;
		else
			tempA = tempB;
		tempB = tempB->next;
	}

	
	tempA = (*pileA);
	tempB = (*pileB);
	while (tempA->content != i)
		tempA = tempA->next;
	while(tempA->target != tempB->content && tempB != NULL)	
		tempB = tempB->next;
	
	/*============MOUV=========*/
		/*============meme sens 0=========*/
	if (tempA->sens == tempB->sens && tempA->sens == 0)
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
			pb(pileA, pileB);
		}
		else if (tempA->mouv <= tempB->mouv)
		{
			tempA->mouv -= tempB->mouv;
			while(tempA->mouv-- > 0)
				rr(pileA, pileB);
			while(tempB->mouv-- > 0)
				rb(pileB);
			if (tempA->content < tempB->content && tempA->closet != 0)
				rb(pileB);
			pb(pileA, pileB);
		}
	} else if (tempA->sens == tempB->sens && tempA->sens == 1)
		/*============meme sens 1=========*/
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
			pb(pileA, pileB);
		}
		else if (tempA->mouv <= tempB->mouv)
		{
			tempA->mouv -= tempB->mouv;
			while(tempA->mouv-- > 0)
				rrr(pileA, pileB);
			while(tempB->mouv-- > 0)
				rrb(pileB);
			if (tempA->content < tempB->content && tempA->closet != 0)
				rb(pileB);
			pb(pileA, pileB);
		}
	} else if (tempA->sens != tempB->sens)
	/*============sens contraire=========*/
	{
		/*_________temp	A________*/
		if (tempA->sens == 0)
			while (tempA->mouv-- > 0)
				ra(pileA);
		else 
			while (tempA->mouv-- > 0)
				rra(pileA);
		/*___________temp b_________*/
		if (tempB->sens == 0)
			while (tempB->mouv-- > 0)
				rb(pileB);
		else 
			while (tempB->mouv-- > 0)
				rrb(pileB);
		// while (tempA->mouv-- > 0)
		// 		ra(pileA);
		// while (tempB->mouv-- > 0)
		// 		rb(pileB);
		//  if (tempA->content < tempB->content && tempA->closet != 0)
		//  	rb(pileB);
		pb(pileA, pileB);
	}
}


// void sorting_pile(t_push **pileA, t_push **pileB)
// {
// 	(pb(pileA, pileB),  pb(pileA, pileB));
//	if ((*pileB)->content > (*pileB)->next->content)
//	 	sb(pileb);
// 	while (ft_lstsize_p((*pileA)) > 3)
// 	{
// 		custom(pileB);
// 		custom_A(pileA);
// 		mouv_pile(pileA, pileB);
//		(clear_param(pileA), clear_param(pileB));
// 	}
// 	if (ft_lstsize_p((*pileA)) == 3)
// 		sort_nbrs_small(pileA);
// 	while (ft_lstsize_p(*pileB) >=  0)
// 	{
// 		/* code */
// 	}
// }

