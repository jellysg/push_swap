#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;
	temp = stack->i;
	stack->i = stack->next->i;
	stack->next->i = temp;
}

/* eg swap a
a = 1 2 3 4

temp = 1
a = 2 2 3 4
a = 2 1 3 4
temp = [0]
i = [0] [1] [2] [3]
i = [1] [1] [2] [3]
i = [1] [0] [2] [3]
*/

void	ft_sa(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}