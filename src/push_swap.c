#include "push_swap.h"

int   main(int argc, char **argv)
{
    int     start_index;
    char    *strategy;
    double  disorder;
    t_stack *stack_a;

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
    stack_a = init_stack(argc, argv, start_index);
    if (!stack_a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    disorder = compute_disorder(stack_a);
    return (0);
}
