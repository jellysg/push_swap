#include "../../includes/push_swap.h"

void	init_a(t_stack **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
    argv = ft_esplit(argv[1], ' ');
	while (argv[i])
	{
		if (syntax_check(argv[i]) != true)
			error_msg(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_msg(a);
		if (duplicate_check(*a, (int)nbr) != true)
			error_msg(a); 
		append_stack(a, (int)nbr);
		i++;
	}
}