#include "./../includes/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		ft_rr(a, b);
	update_position(*a);
	update_position(*b);
}

void	rrotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		ft_rrr(a, b);
	update_position(*a);
	update_position(*b);
}

void	top_of_stack(t_stack **stack, t_stack *cheapest, char selected)
{
	while (*stack != cheapest)
	{
		if (selected == 'a')
		{
			if (cheapest->top_half == true)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (selected == 'b')
		{
			if (cheapest->top_half == true)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}	
	}
}

void	move_to(t_stack **a, t_stack **b, char dest)
{
	t_stack	*cheapest;

	if (dest == 'a')
	{
		top_of_stack(a, (*b)->target, 'a');
		ft_pa(a, b); 
    }
    else if (dest == 'b')
    {
		cheapest = get_cheapest(*a); 
		if (cheapest->top_half == true && cheapest->target->top_half == true)
			rotate_both(a, b, cheapest);
		else if (cheapest->top_half == false && cheapest->target->top_half == false)
			rrotate_both(a, b, cheapest);
		top_of_stack(a, cheapest, 'a');
		top_of_stack(b, cheapest->target, 'b'); 
		ft_pb(a, b);
    }
}

void	asc_sort(t_stack **a)
{
	while ((*a)->num != ft_smallest(*a)->num)
	{
		if (ft_smallest(*a)->top_half == true)
			ft_ra(a);
		else
			ft_rra(a);
	}
}