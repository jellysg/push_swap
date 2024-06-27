#include "../includes/push_swap.h"

void append_stack(t_stack **stack, int value)
{
    t_stack *node;
    t_stack *last;

    if (stack == NULL)
        return;

    node = malloc(sizeof(t_stack));
    if (node == NULL)
        return;
    node->num = value;
    node->next = NULL;
    if (*stack == NULL)
        *stack = node;
    else
    {
        last = stack_last(*stack);
        last->next = node;
    }
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