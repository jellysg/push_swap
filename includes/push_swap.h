#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
    int num;
    int i;
    int cost;
    bool top_half;
    bool cheapest;
    struct s_stack  *target;
    struct s_stack  *next;
}   t_stack;

// init
void	init_a(t_stack **a, char **argv);

// ft_esplit
// static int	wcount(char *s, char c);
// static char	*get_next_word(char *s, char c);
char **ft_esplit(char *s, char c);

// error
bool	syntax_check(char *str);
bool	duplicate_check(t_stack *a, int nbr);
void	free_stack(t_stack **stack);
void	error_msg(t_stack **a);

// operations
// push
void	push(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
// swap
void	swap(t_stack *stack);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
// rotate
void	rotate(t_stack **stack);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
// reverse rotate
void	r_rotate(t_stack **stack);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

// operations utils
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_before_last(t_stack *stack);
int	get_stack_size(t_stack	*stack);

#endif