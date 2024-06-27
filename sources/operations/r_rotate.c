#include "../includes/push_swap.h"

void r_rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *before_last;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	last = stack_last(*stack);
	before_last = stack_before_last(*stack);
	if (before_last)
		before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

/* eg rrotate a
a = 2 3 4 1

last = 2 3 4 (1) = 1
before_last = 2 3 (4) 1 = 4 1
before_last = 4
^ this step will change the last value to NULL, so the stack now = 2 3 4
last = 1 2 3 4
stack = 1 2 3 4
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