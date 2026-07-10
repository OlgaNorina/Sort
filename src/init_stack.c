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

int check_is_valid_number(char *arg)
{   
    int i;

    i = 0;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    if (arg[i] == '\0')
        return (0);
    while (arg[i] != '\0')
    {
        if (!ft_isdigit(arg[i]))
            return (0);
        i++;
    }
    return (1);
}

t_stack *init_stack(int argc, char **argv, int start_index)
{
    t_stack *stack;
    char    **chrlst;
    int     i;
    int     number;
    int     index;

    index = start_index;
    //printf("%d", index);
    stack = NULL;
    while (index < argc)
    {
        chrlst = ft_split(argv[index], ' '); 
        //здесь эта функция либо берет за раз один символ, если без кавычек. Потом мы его используем в следующем цикле.
        //В этом случае будет просто массив с 1 индексом
        //ЛИБО берет сразу строку и дальше мы проходим по ней через i в следующем цикле.
        //ПОДУМАЮ как сделать проверку на количество цифр, что их больше чем 1.
        if (!chrlst)
            return (NULL);
        i = 0;
        while (chrlst[i] != NULL) //В этом цикле начинаем посимвольно делать провекру (не зависимо от формата передачи: с "" или без)
        //и формировать стэк
        {
            if (check_is_valid_number(chrlst[i]) == 0)// выполняется проверка, что символ - digit, при этом первый + и - пропускается.
            {
                write(2, "Error\n", 6);
                return (NULL); //!!!НУЖНА еще фукнция очистки stack и chrlst
            }
            number = ft_atoi(chrlst[i]);//если digit с одним +/- приводим к типу int с помощью atoi
            printf("%d\n", number); //Проверяем, что в итоге дошло до атои
            //Чтобы проверить дубликаты нужен стек. ПОКА думаю, что это будет лучше решение.
            /*
            if (ft_isduplicate(stack, number)) //нужен стэк для тестирования
            {
                write(2, "Error\n", 6);
                return(NULL); //!!!НУЖНА еще фукнция очистки stack и chrlst
            }
            add_new_node(&stack, number); //Нужен стэк для тестирования
            */
            i++;
        }
        free(chrlst);//после цикла сразу очищаем. И переходим к следующему. Не накапливается.
        //!!!НУЖНА еще функция, которая очистить сам массив, а не только указатели.
        index++;
    }
    return (stack);
}