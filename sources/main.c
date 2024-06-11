#include "./../includes/push_swap.h"

void    push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a) == false)
	{
		if (stack_size(a) == 2)
			ft_sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
}

bool    arg_check(int argc, char **argv)
{
    if (argc == 2 && argv[1][0])
        return (true);
    return (false);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (arg_check(argc, argv) != true)
        return (1);
	argv = ft_esplit(argv[1], ' ');
	init_a(&a, argv + 1);
	push_swap(a, b);
	free_stack(&a);
	return (0);
}