#include "push_swap.h"

int   main(int argc, char **argv)
{
    int     start_index;
    char    *strategy;
    double  disorder;
    t_stack *stack_a;

    if (argc < 2)
        return (0);
    start_index = 1; //нулевой индекс argv[0] - это имя программы, поэтому начинаем со первого 
    strategy = get_strategy(argv[1]); //извлекаем стратегию (флаг), если передана
    if (strategy) // если предыдущий вызов вернул значение, а не ноль, 
        start_index++; // то необходимо начать со второго индекса, т.к. 1 - флаг. Свигаем индекс.
    else
        strategy = "adaptive";// если флаг не передан, принимаем по умолчанию данное значение, 
                                //которое предполагает, что мы сами решаем, как определять тип сортировки
    if ((argc - start_index) == 1 && !ft_strchr(argv[start_index], ' ')) //1 может быть, если после флага/команды только 1 цифра ИЛИ строка в ""
    //тогда проверяем пробел в строке. Если его нет, значит в ней только одно число, что тоже не подходит
        return (0);
    stack_a = init_stack(argc, argv, start_index); //инициализация стэка
    if (!stack_a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    disorder = compute_disorder(stack_a); //рассчитываем метрику неупорядоченности (еще не тестировала)
    return (0);
}