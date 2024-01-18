/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:33:22 by scely             #+#    #+#             */
/*   Updated: 2024/01/17 16:51:27 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_push
{
	int					content;
	struct s_push		*prev;
	struct s_push		*next;
}	t_push;

int		set_pile(t_push **pile_A, char **ac, int i);
void	print_pile_A(t_push *set_pile_A , char pile);
t_push	*ft_lstlast_p(t_push *lst);
t_push	*ft_lstnew_p(int content);
void	ft_lstadd_back_p(t_push **lst, t_push *new);
void	ft_lstadd_front_p(t_push **lst, t_push *new);

void	sa(t_push **pile_A);
void	sb(t_push **pile_B);
void	ss(t_push **pile_A, t_push **pile_B);

void	pa(t_push **pile_A, t_push **pile_B);
void	pb(t_push **pile_A, t_push **pile_B);

void	ra(t_push **pile_A);
void	rb(t_push **pile_B);
void	rr(t_push **pile_A, t_push **pile_B);
void	rra(t_push **pile_A);
void	rrb(t_push **pile_b);
void	rrr(t_push **pile_A, t_push **pile_B);

int		list_sorted(t_push **pile);
void	sort_nbrs_small(t_push **pile);
int		doublons(t_push **pileA);
int		len_nbrs(char *nbrs);
/*===================================*/
int check_numbers(char *str);
/*===================================*/



#endif