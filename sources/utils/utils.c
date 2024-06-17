#include "../../includes/push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	update_position(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = stack_size(stack) / 2;
	{
		stack->i = i;
		if (i <= middle)
			stack->top_half = true;
		else
			stack->top_half = false;
		stack = stack->next;
		i++;
	}
}

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (-1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*ft_biggest(t_stack *stack)
{
	long			biggest;
	t_stack	*b_index;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (biggest < stack->num)
		{
			biggest = stack->num;
			b_index = stack;
		}
		stack = stack->next;
	}
	return (b_index);
}

t_stack	*ft_smallest(t_stack *stack)
{
	long			smallest;
	t_stack	*s_index;

	if (!stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (smallest > stack->num)
		{
			smallest = stack->num;
			s_index = stack;
		}
		stack = stack->next;
	}
	return (s_index); 
}