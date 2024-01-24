/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:11 by scely             #+#    #+#             */
/*   Updated: 2024/01/24 18:12:34 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_pile(t_push **pile_A, char **av, int i)
{
	t_push	*list;

	while (av[i])
	{
		if (check_numbers(av[i]) != 0 || len_nbrs(av[i]) != 0)
			return (-1);
		list = ft_lstnew_p(ft_atoi(av[i]));
		list->next = NULL;
		ft_lstadd_back_p(pile_A, list);
		i++;
	}
	return (0);
}

void	push_swap(t_push **pile_a, t_push **pile_b)
{
	if (ft_lstsize_p(*pile_a) == 2)
		(sa(pile_a));
	else if (ft_lstsize_p(*pile_a) == 3)
		sort_nbrs_small(pile_a);
	else if (ft_lstsize_p(*pile_a) == 4)
		sort_four(pile_a, pile_b);
	else if (ft_lstsize_p(*pile_a) > 4)
		all_insruction(pile_a, pile_b);
}

void	free_lst(t_push **pile)
{
	t_push	*temp_a;

	while ((*pile) != NULL)
	{
		temp_a = (*pile)->next;
		free((*pile));
		(*pile) = temp_a;
	}
	free(pile);
}

int	main(int ac, char **av)
{
	t_push	**pile_a;
	t_push	**pile_b;
	int		i;

	i = 1;
	if (ac == 1 || (ft_strchr(av[1], 32) != 0 && av[2] != NULL))
		return (ft_putstr_fd("Error\n", 2), 1);
	pile_a = ft_calloc(sizeof(t_push), 1);
	pile_b = ft_calloc(sizeof(t_push), 1);
	if (ac == 2 && ft_strchr(av[1], 32) != 0)
	{
		av = ft_split(av[1], 32);
		i = 0;
	}
	if (set_pile(pile_a, av, i) != 0 || doublons(pile_a) != 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (list_sorted(pile_a) == 0)
		return (0);
	push_swap(pile_a, pile_b);
	if (i == 0)
		ft_free(av);
	(free_lst(pile_a), free_lst(pile_b));
	return (0);
}
