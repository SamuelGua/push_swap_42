/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meca_971 <meca_971@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:33:22 by scely             #+#    #+#             */
/*   Updated: 2024/01/20 19:45:17 by meca_971         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_push
{
	int					content; // le nombre
	int					cost; // pour le push dans la pileb et pour mettre dans la bonne position dans la pileb
	int					mouv; // nombre de mouvement a effectuer
	int					sens; // rr ou rrr
	int					target; // ou va ton le mettre
	int					closet;
	struct s_push		*prev;
	struct s_push		*next;
}	t_push;

int		set_pile(t_push **pile_A, char **ac, int i);
void	print_pile_A(t_push *set_pile_A , char pile);
t_push	*ft_lstlast_p(t_push *lst);
t_push	*ft_lstnew_p(int content);
void	ft_lstadd_back_p(t_push **lst, t_push *new);
void	ft_lstadd_front_p(t_push **lst, t_push *new);
int		ft_lstsize_p(t_push *lst);

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

/*===================================*/
void	custom(t_push **pile);
void	custom_A(t_push **pileA, t_push **pileB);
void	clear_param(t_push **pile);
void	turk_sorting(t_push **pileA, t_push **pileB);


/*===================================*/



#endif