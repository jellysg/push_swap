#include "./../includes/push_swap.h"

void    start_a(t_stack **a, t_stack **b)
{
    while ((*a)->size > 3 && !is_sorted(*a))
	{
		calc_a(*a, *b);
		move_to_b(a, b);
        (*a)->size--;
	}
}

void    end_b(t_stack **a, t_stack **b)
{
	while (*b)
	{
		calc_b(*a, *b);
		move_to_a(a, b);
	}
}

void    init_push(t_stack **a, t_stack **b)
{
	if ((*a)->size > 3 && !is_sorted(*a))
    {
		ft_pb(a, b);
        (*a)->size--;
    }
	if ((*a)->size > 3 && !is_sorted(*a))
    {
		ft_pb(a, b);
        (*a)->size--;
    }
}

void	turk_algo(t_stack **a, t_stack **b)
{
	init_push(a, b);
    start_a(a, b);
	sort_three(a);
    end_b(a, b);
	position_index(*a);
	asc_sort(a);
}