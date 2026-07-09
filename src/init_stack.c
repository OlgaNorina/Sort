#include "push_swap.h"
#include <stdio.h>

int ft_isduplicate(t_stack *stack, int  new_number)
{
    while (stack != NULL)
    {
        if (stack->value == new_number)
            return (1);
        stack = stack->next;
    }
    return (0);
}

t_stack *init_stack(int argc, char **argv, int start_index)
{
    t_stack *stack;
    char    **chrlst;
    int     i;
    int     number;
    
    stack = NULL;
    while (start_index < argc)
    {
        chrlst = ft_split(argv[start_index], ' ');
        if (!chrlst)
            return (NULL);
        i = 0;
        while (chrlst[i] != NULL)
        {
            number = ft_atoi(chrlst[i]);
            //printf("%d\n", number);
            if (ft_isduplicate(stack, number))
            {
                write(2, "Error\n", 6);
                return(NULL); //FREE!
            }
            add_new_node(&stack, number);
            i++;
        }
        free(chrlst);
        start_index++;
    return (stack);
}