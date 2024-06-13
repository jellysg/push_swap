#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
    int num;
    int i;
    int cost;
    int size;
    bool top_half;
    bool cheapest;
    struct s_stack  *target;
    struct s_stack  *next;
}   t_stack;

// ./core/
// calc_a.c (5/5 functions)
void	position_index(t_stack *stack);
void	cheapest_cost(t_stack *stack);
void	calc_a(t_stack *a, t_stack *b);
// sort_three.c (1/5 functions)
void	sort_three(t_stack **a);
// turk_algo.c (4/5 functions)
void    start_a(t_stack **a, t_stack **b);
void    end_b(t_stack **a, t_stack **b);
void    init_push(t_stack **a, t_stack **b);
void	turk_algo(t_stack **a, t_stack **b);

// ./operations/
// push.c (3/5 functions)
void	push(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
// swap.c (4/5 functions)
void	swap(t_stack *stack);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
// rotate.c (4/5 functions)
void	rotate(t_stack **stack);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
// r_rotate.c (4/5 functions)
void	r_rotate(t_stack **stack);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

// ./utils/
// init.c (1/5 functions)
void	init_a(t_stack **a, char **argv);
// error.c (4/5 functions)
bool	syntax_check(char *str);
bool	duplicate_check(t_stack *a, int nbr);
void	free_stack(t_stack **stack);
void	error_msg(t_stack **a);
// utils.c (3/5 functions)
bool	is_sorted(t_stack *stack);
t_stack	*ft_biggest(t_stack *stack);
t_stack	*ft_smallest(t_stack *stack);
// utils2.c (3/5 functions)
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_before_last(t_stack *stack);
int	stack_size(t_stack	*stack);
// ft_esplit.c (5/5 functions)
char	**ft_esplit(char *s, char c);

#endif