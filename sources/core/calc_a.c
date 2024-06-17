#include "./../includes/push_swap.h"

void	link_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*link;
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
				link = current_b;
			}
			current_b = current_b->next;
		}
		if (nearest_lower == LONG_MIN)
			a->target = ft_biggest(b);
		else
			a->target = link;
		a = a->next;
	}
}

void	cost_a(t_stack *a, t_stack *b)
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

void	cheapest_a(t_stack *stack)
{
	long			cheapest;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (cheapest > stack->cost)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	calc_a(t_stack *a, t_stack *b)
{
	update_position(a);
	update_position(b);
	link_a(a, b);
	cost_a(a, b);
	cheapest_a(a);
}