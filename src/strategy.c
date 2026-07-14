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
    while(current != NULL)//
    {
        next_node = current->next;//Присвоение next_node: следующей по отношению к текущему для сравнения
        while(next_node != NULL)//Переход в цикле пока в next не будет NULL
        {
            total_pairs++;//Счетчик количества переходов = количество пар для сравнения
            if (current->value > next_node->value)//Сравнение текущего и следующего числа
                mistakes++;//+ счетчик, если предыдущее больше следующего
            next_node = next_node->next;//Переход к следующему
        }
        current = current->next;//Следующий элемент принимается как текущий
    }
    return ((double)mistakes / total_pairs);
}
