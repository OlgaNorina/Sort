#include "push_swap.h"

t_stack *init_stack_node(int new_value)
{
    t_stack    *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = new_value;
    new_node->index = 0;
    new_node->next = NULL;
    return (new_node);
}

void    add_new_node_last(t_stack **stack, t_stack *new_node)
{
    t_stack *last;

    if (stack && new_node)
    {
	if (!*stack)
        	*stack = new_node;
    	else
    	{
        	last = *stack;
        	while (last->next)
            		last = last->next;
        	last->next = new_node;   
    	}
    }
}
