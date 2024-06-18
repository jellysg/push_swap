#include "./../includes/push_swap.h"

void	link_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*link;
	long			nearest_higher;

	while (b)
	{
		nearest_higher = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < nearest_higher)
			{
				nearest_higher = current_a->num;
				link = current_a;
			}
			current_a = current_a->next;
		}
		if (nearest_higher == LONG_MAX)
			b->target = ft_smallest(a);
		else
			b->target = link;
		b = b->next;
	}
}

void	calc_b(t_stack *a, t_stack *b)
{
	update_position(a);
	update_position(b);
	link_b(a, b);
}