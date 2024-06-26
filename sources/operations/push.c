#include "../includes/push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*b == NULL)
	{
		*b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *b;
		*b = temp;
	}
}

/* eg push b
a = 1 2 3 4
b = 5 6 7 8

temp = 1 2 3 4
a = 2 3 4
temp = 1 5 6 7 8
b = 1 5 6 7 8

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