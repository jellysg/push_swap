#include "../includes/push_swap.h"

void rotate(t_stack **stack)
{
	t_stack *last;
	t_stack *temp;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
	temp = *stack;
	last = stack_last(*stack);
	*stack = temp->next;
	last->next = temp;
	temp->next = NULL;
}

/* eg rotate a
a = 4 1 2 3

temp = 4 1 2 3
last = 4 1 2 (3) = 3
a = 1 2 3
last = 3 4 1 2 3
(now a = 1 2 3 4 1 2 3)
temp = 4
(now a = 1 2 3 4)
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