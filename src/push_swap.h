#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct  s_stack 
{
    int             value;
    int             index;
    struct s_stack  *next;
} t_stack;

char    *get_strategy(char *str);
double compute_disorder(t_stack *stack_a);

#endif