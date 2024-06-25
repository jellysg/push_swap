#include "../../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int	    sign;
    int		i;

	result = 0;
	sign = 1;
    i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
		    sign = -1;
		i++;
    }
	while (ft_isdigit(str[i]))
    {
		result = (result * 10) + (str[i] - '0');
        i++;
    }
	return (result * sign);
}

void	init_a(t_stack **a, char **array)
{
	long	nbr;
    int		num;
	int		i;

	i = 0;
	while (array[i])
	{
		if (syntax_check(array[i]) == false)
			error_msg(a, array);
		nbr = ft_atol(array[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_msg(a, array);
        num = (int)nbr;
		if (duplicate_check(*a, num) == true)
			error_msg(a, array); 
		append_stack(a, num);
		i++;
	}
}