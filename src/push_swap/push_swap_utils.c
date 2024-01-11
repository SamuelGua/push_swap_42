/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:06 by scely             #+#    #+#             */
/*   Updated: 2024/01/11 12:10:37 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_lstlast_p(t_push *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_push	*ft_lstnew_p(int content)
{
	t_push	*new;

	new = malloc(sizeof(t_push));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_p(t_push **lst, t_push *new)
{
	t_push	*liste;

	if (*lst)
	{
		liste = ft_lstlast_p(*lst);
		liste->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front_p(t_push **lst, t_push *new)
{
	new->next = *lst;
	*lst = new;
}

void	set_pile(t_push **pile_A, char **av)
{
	t_push	*list;
	int		i;

	i = 1;
	while (av[i])
	{
		if(check_numbers(av[i]) != 0 && len_nbrs(av[i]) != 0)
			return ;
		list = ft_lstnew_p(ft_atoi(av[i]));
		list->next = NULL;
		ft_lstadd_back_p(pile_A, list);
		i++;
	}
}
