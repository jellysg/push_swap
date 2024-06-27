#include "./../includes/push_swap.h"

void    push_swap(t_stack *a, t_stack *b, char **argv, int argc)
{
	a->size = stack_size(a);
	if (is_sorted(a) == false)
	{
		if (a->size == 2)
			ft_sa(&a);
		else if (a->size == 3)
			sort_three(&a);
		else if (a->size > 3)
			turk_algo(&a, &b);
	}
	if (argc == 2)
		free_array(argv);
	free_stack(&a);
	(void)argv;
}

bool	arg_check(int argc, char **argv)
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
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_esplit(argv[1], ' ');
	else
		argv = argv + 1;
	init_a(&a, argv, argc);
	push_swap(a, b, argv, argc);
	return (0);
}