#include "./../includes/push_swap.h"

void	link_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*link;
	long			nearest_lower;

	while (a)
	{
		nearest_lower = LONG_MIN;
		current_a = b;
		while (current_a)
		{
			if (current_a->num < b->num && current_a->num > nearest_lower)
			{
				nearest_lower = current_a->num;
				link = current_a;
			}
			current_a = current_a->next;
		}
		if (nearest_lower == LONG_MIN)
			b->target = ft_biggest(b);
		else
			b->target = link;
		a = b->next;
	}
}

void	cost_b(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		b->cost = b->i;
		if (!(b->top_half))
			b->cost = size_a - (b->i);
		if (b->target->top_half)
			b->cost += b->target->i;
		else
			b->cost += size_b - (b->target->i);
		a = b->next;
	}
}

void	cheapest_b(t_stack *stack)
{
	long			cheapest;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MIN;
	while (stack)
	{
		if (cheapest < stack->cost)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	calc_b(t_stack *a, t_stack *b)
{
	update_position(a);
	update_position(b);
	link_b(a, b);
	cost_b(a, b);
	cheapest_b(a);
}