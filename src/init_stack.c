#include "push_swap.h"

t_stack init_stack(int argc, char **argv, int start_index)
{
    t_stack *stack;
    char    **chrlst;
    int     j;
    
    stack = NULL;
    while (start_index < argc)
    {
        chrlst = ft_split(argv[start_index], ' ');
        if (!words || !words[0])
            return (NULL); // Добавить очистку стэка и chrlst
        j = 0;
        while (chrlst[j])
        {
            //
        }
    }
}