#include "push_swap.h"

int   main(int argc, char *argv[])
{
    int     start_index;
    char    *strategy;
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);
    start_index = 1;
    strategy = get_strategy(argv[1]);
    if (strategy)
    {
        start_index++;
        if (argc < 3)
            return (0);
    }
    else
        strategy = "adaptive";
    return (0);
}
