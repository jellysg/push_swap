#include "./../includes/push_swap.h"

void    start_a(t_stack **a, t_stack **b)
{
    int size;

    size = (*a)->size;
    while (size > 3 && is_sorted(*a) == false)
	{
		calc_a(*a, *b);
		move_to(a, b, 'b');
        size--;
	}
    (*a)->size = size;
}

void    end_b(t_stack **a, t_stack **b)
{
	while (*b)
	{
		calc_b(*a, *b);
		move_to(a, b, 'a');
	}
}

void    init_push(t_stack **a, t_stack **b)
{
	int	size;
    int pushed;

	size = (*a)->size;
    pushed = 0;
	while (size > 3 && pushed < 2 && is_sorted(*a) == false)
    {
		ft_pb(a, b);
        size--;
        pushed++;
    }
    (*a)->size = size;
}

void	turk_algo(t_stack **a, t_stack **b)
{
	init_push(a, b);
    start_a(a, b);
	sort_three(a);
    end_b(a, b);
	update_position(*a);
	asc_sort(a);
}