/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:06 by scely             #+#    #+#             */
/*   Updated: 2024/01/19 10:17:02 by meca_971         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_p(t_push *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

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
		new->prev = liste;
	}
	else
	{
		*lst = new;
		new->prev = NULL;
	}
}

void	ft_lstadd_front_p(t_push **lst, t_push *new)
{
	new->next = *lst;
	*lst = new;
}

int	set_pile(t_push **pile_A, char **av, int i)
{
	t_push	*list;

	while (av[i])
	{
		if(check_numbers(av[i]) != 0 || len_nbrs(av[i]) != 0)
			return (-1);
		list = ft_lstnew_p(ft_atoi(av[i]));
		list->next = NULL;
		ft_lstadd_back_p(pile_A, list);
		i++;
	}
	//(*pile_A)->prev = NULL;
	return (0);
}
