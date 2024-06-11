#include "../includes/push_swap.h"

void	r_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*before_last;

	last = stack_last(*stack);
	before_last = stack_before_last(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	before_last->next = NULL;
}

/* eg rrotate a
a = 1 2 3 4

last = 1 2 3 (4)
before_last = 1 2 (3) 4
temp = 1 2 3 4
a = 4
a = 4 1 2 3 4
a = 4 1 2 3 NULL
*/

void	ft_rra(t_stack **a)
{
	r_rotate(a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **b)
{
	r_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	ft_printf("rrr\n");
}