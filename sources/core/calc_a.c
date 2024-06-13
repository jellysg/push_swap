#include "./../includes/push_swap.h"

void	position_index(t_stack *stack)
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

static void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long			nearest_lower;

	while (a)
	{
		nearest_lower = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num && current_b->num > nearest_lower)
			{
				nearest_lower = current_b->num;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (nearest_lower == LONG_MIN)
			a->target = ft_biggest(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	cost_a(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		a->cost = a->i;
		if (!(a->top_half))
			a->cost = size_a - (a->i);
		if (a->target->top_half)
			a->cost += a->target->i;
		else
			a->cost += size_b - (a->target->i);
		a = a->next;
	}
}

void	cheapest_cost(t_stack *stack)
{
	long			cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	calc_a(t_stack *a, t_stack *b)
{
	position_index(a);
	position_index(b);
	target_a(a, b);
	cost_a(a, b);
	cheapest_cost(a);
}