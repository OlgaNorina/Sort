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
double  compute_disorder(t_stack *stack_a);
t_stack *init_stack(int argc, char **argv, int start_index);
int     ft_isduplicate(t_stack *stack, int  size);
int     check_is_valid_number(char *arg);
t_stack *init_stack_node(int new_value);
void    add_new_node_last(t_stack **stack, t_stack *new_node);
void    print_stack(t_stack *stack);//Для тестирования
void    free_array(char **arg);
void    free_stack(t_stack **stack);
int     check_and_parse(t_stack **stack, char **arr);
char    *get_strategy_by_disorder(double disorder);

#endif
