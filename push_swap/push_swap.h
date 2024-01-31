/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:31:45 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/12/11 02:50:33 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				cur_pos;
	int				targ_pos;
	int				a_cost;
	int				b_cost;
	struct s_stack	*next;
}	t_stack;

/////////////////////////////
//          main.c         //
/////////////////////////////

void	ft_exit(t_stack **stack_a, t_stack **stack_b);
void	ft_free(t_stack **stack);
int		ft_sort_status(t_stack *s);

/////////////////////////////
//          check.c        //
/////////////////////////////

int		ft_zero_check(char *av);
int		ft_check_args(char *av);
int		ft_valid_input(char **av);
int		ft_dupe_checker(char **av);

/////////////////////////////
//      decisions.c        //
/////////////////////////////

void	ft_stack_improve(t_stack **stack_a);
void	ft_sort_small(t_stack **stack);
void	ft_long_sort(t_stack **a, t_stack **b);
void	ft_get_cost(t_stack **stack_a, t_stack **stack_b);

/////////////////////////////
//     ft_push.c           //
/////////////////////////////

void	ft_push(t_stack **src, t_stack **dest);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);

/////////////////////////////
//     ft_swap.c           //
/////////////////////////////

void	ft_swap(t_stack *stack);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

/////////////////////////////
//     locate_ops.c        //
/////////////////////////////

void	ft_pos(t_stack **stack);
int		ft_min_pos(t_stack **stack);
int		ft_find_target(t_stack **a, int b_idx, int targ_index, int targ_pos);
void	ft_target_pos(t_stack **a, t_stack **b);

/////////////////////////////
//     move_rb_ra.c        //
/////////////////////////////

void	ft_rot_a(t_stack **a, int *cost);
void	ft_rot_b(t_stack **b, int *cost);
void	ft_make_movement(t_stack **a, t_stack **b, int c_a, int c_b);
void	ft_cheapest_to_a(t_stack **stack_a, t_stack **stack_b);

/////////////////////////////
//    reverse_ops.c        //
/////////////////////////////

void	ft_reverse(t_stack **stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rev_all(t_stack **a, t_stack **b, int *c_a, int *c_b);

/////////////////////////////
//     rotate_ops.c        //
/////////////////////////////

void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rot_all(t_stack **a, t_stack **b, int *c_a, int *c_b);

/////////////////////////////
//     stack_init.c        //
/////////////////////////////

t_stack	*ft_stack_fill(int ac, char **av);
void	ft_indexator(t_stack *stack_a, int size);

/////////////////////////////
//       stacks.c          //
/////////////////////////////

int		ft_max_index(t_stack *stack);
t_stack	*ft_stack_last(t_stack *s);
t_stack	*ft_stack_bfor_last(t_stack *s);
t_stack	*ft_stack_make(int nbr);
void	ft_stack_append(t_stack **stack, t_stack *add);

/////////////////////////////
//         utils.c         //
/////////////////////////////

int		ft_is_sign(char c);
int		ft_is_digit(char c);
int		ft_size(t_stack	*stack);

#endif
