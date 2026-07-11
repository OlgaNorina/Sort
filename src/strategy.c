#include "push_swap.h"

char    *get_strategy(char *str)
{
    char    *strategy;

    strategy = NULL;
    if (ft_strcmp(str, "--simple") == 0)
            strategy = "simple";
    else if (ft_strcmp(str, "--medium") == 0)
            strategy = "medium";
    else if (ft_strcmp(str, "--complex") == 0)
            strategy = "complex";
    else if (ft_strcmp(str, "--adaptive") == 0)
            strategy = "adaptive";
    return (strategy);
}


double compute_disorder(t_stack *stack_a)
{
    int mistakes;
    int total_pairs;
    t_stack *current;
    t_stack *next_node;

    mistakes = 0;
    total_pairs = 0;
    current = stack_a;
    while(current != NULL)
    {
        next_node = current->next;
        while(next_node != NULL)
        {
            total_pairs++;
            if (current->value > next_node->value)
                mistakes++;
            next_node = next_node->next;
        }
        current = current->next;
    }
    return ((double)mistakes / total_pairs);
}
