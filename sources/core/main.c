#include "./../includes/push_swap.h"

void    push_swap(t_stack *a, t_stack *b)
{
    a->size = stack_size(a);
	if (is_sorted(a) == false)
	{
		if (a->size == 2)
			ft_sa(&a);
		else if (a->size == 3)
			sort_three(&a);
		else
			turk_algo(&a, &b);
	}
}

bool    arg_check(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (false);
    return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (arg_check(argc, argv) == false)
        return (1);
    else if (argc == 2)
	    argv = ft_split(argv[1], ' ');
	init_a(&a, argv + 1);
	push_swap(a, b);
	free_stack(&a);
	return (0);
}