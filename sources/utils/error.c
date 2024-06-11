#include "../../includes/push_swap.h"

bool	syntax_check(char *str)
{
    int i;

    i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (false);
	if ((str[i] == '+' || str[i] == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (false);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
        i++;
	}
	return (true);
}

bool	duplicate_check(t_stack *a, int nbr)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->num == nbr)
			return (true);
		a = a->next;
	}
	return (false);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		curr->num = 0;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

void	error_msg(t_stack **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}