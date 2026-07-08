#include "push_swap.h"

int	ft_atoi(const char *nptr); //temp

int   main(int argc, char *argv[])
{
    int     i;
    int     num_array[argc - 1];
    int     temp;
    t_stack *stack_a;
    t_stack *stack_b;

    i = 0;
    while (i < argc - 1)
    {
        temp = ft_atoi(argv[i + 1]);
        num_array[i] = temp;
        i++;
    }
    i = 0;
    while (i < argc - 1)
    {
        printf("%d ", num_array[i]);
        i++;
    }
    return (0);
}