/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:39:11 by scely             #+#    #+#             */
/*   Updated: 2024/01/24 13:43:33 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_push **pile_a, t_push **pile_b)
{
	if (ft_lstsize_p(*pile_a) == 2)
		(sa(pile_a));
	else if (ft_lstsize_p(*pile_a) == 3)
		sort_nbrs_small(pile_a);
	else if (ft_lstsize_p(*pile_a) == 5)
		return ;
	else if (ft_lstsize_p(*pile_a) > 5)
		all_insruction(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	t_push	**pile_a;
	t_push	**pile_b;
	int		i;

	i = 1;
	if (ac == 1 || (ft_strchr(av[1], 32) != 0 && av[2] != NULL))
		return (ft_putstr_fd("Error\n", 2), 1);
	pile_a = malloc(sizeof(t_push));
	pile_b = malloc(sizeof(t_push));
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
	return (0);
}
