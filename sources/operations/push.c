#include "../includes/push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
}

/* eg push b
a = 1 2 3 4
b = 5 6 7 8

temp = 2 3 4
a = 1 5 6 7 8
b = 1 5 6 7 8
a = 2 3 4

result
a = 2 3 4
b = 1 5 6 7 8
*/

void	ft_pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	ft_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}