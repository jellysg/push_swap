#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack;
	*stack = (*stack)->next;
	last = stack_last(*stack);
	temp->next = NULL;
	last->next = temp;
}

/* eg rotate a
a = 1 2 3 4

temp = 1 2 3 4
a = 2 3 4
last = 1 2 3 (4)
temp = 1 NULL
a = 2 3 4 1
*/

void	ft_ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}