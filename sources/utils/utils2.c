#include "../includes/push_swap.h"

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

    new->next = NULL;
	if (*stack)
	{
		last = stack_last(*stack);
		last->next = new;
	}
	else
		*stack = new;
}

void	append_stack(t_stack **stack, int n)
{
	t_stack	*node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->num = n;
    node->next = NULL;
	stack_add_back(stack, node);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}