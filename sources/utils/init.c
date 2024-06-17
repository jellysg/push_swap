#include "../../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
    int		i;

	result = 0;
	sign = 1; 
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

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