#include "./../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = ft_biggest(*a);
	if (biggest == *a)
		ft_ra(a);
	else if ((*a)->next == biggest)
		ft_rra(a);
	if ((*a)->num > (*a)->next->num)
		ft_sa(a);
}