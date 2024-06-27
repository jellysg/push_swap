#include "../../includes/push_swap.h"

bool	syntax_check(char *str)
{
    int i;

    i = 0;
	if (!(str[i] == '+' || str[i] == '-' || ft_isdigit(str[i]) == 1))
		return (false);
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[1]) == 0)
		return (false);
    i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
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

	curr = *stack;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

void	error_msg(t_stack **a, char **array, int argc)
{
    if (argc == 2)
	    free_array(array);
	if (a && *a)
		free_stack(a);
	ft_printf("Error\n");
	exit(1);
}