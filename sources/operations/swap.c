#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *top;
	t_stack *second;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;
    top = *stack;
    second = (*stack)->next;
	top->next = second->next;
	second->next = top;
	*stack = second;
}

/* eg swap a
a = 2 1 3 4

top = 2 1 3 4
second = 1 3 4
top = 2 3 4
second = 1 2 3 4
a = 1 2 3 4
*/

void	ft_sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}