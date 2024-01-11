/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:38:14 by scely             #+#    #+#             */
/*   Updated: 2024/01/11 12:00:30 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_numbers(char *str)
{
	int	i;

	i = 0;
	while(str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != 0)
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int doublons(t_push **pileA)
{
	t_push *tempA;
	t_push *tempB;

	tempA = (*pileA);
	tempB = (*pileA)->next;
	while (tempA->next != NULL)
	{
		tempB = tempA->next;
		while (tempB != NULL)
		{
			if (tempA->content == tempB->content)
				return (-1);
			tempB = tempB->next;
		}
		tempA = tempA->next;
	}
	return (0);
}

int len_nbrs(char *nbrs)
{
	int	i;

	i = ft_atol(nbrs);
	if (i >= -2147483648 && i <= -2147483647)
		return (0);
	else
		return (-1);
		
}
