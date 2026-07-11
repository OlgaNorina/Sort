#include "push_swap.h"
#include <stdio.h>

int	ft_isduplicate(t_stack *stack, int  new_number)
{
	while (stack != NULL)
	{
		if (stack->value == new_number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_is_valid_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')//Пропускаем +/-
		i++;
	if (arg[i] == '\0')//Проверка, что передан не просто +/-
		return (0);
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))//Если дальше идет иной символ, вернуть 0
			return (0);
		i++;
	}
	return (1);
}

t_stack	*init_stack(int argc, char **argv, int start_index)
{
	t_stack	*stack;
	t_stack	*new_node;
	char	**chrlst;
	int	i;
	int	number;
	int	index;

	index = start_index;
	stack = NULL;
	while (index < argc)
	{
		chrlst = ft_split(argv[index], ' '); //Массив из одного элемента ЛИБО более если строка ""
		if (!chrlst)
			return (NULL);
		i = 0;
		while (chrlst[i] != NULL)
		{
			if (check_is_valid_number(chrlst[i]) == 0)//проверка, что символ - digit
			{
				write(2, "Error\n", 6);
				return (free_array(chrlst), NULL); //!!!НУЖНА еще фукнция очистки stack
			}
			number = ft_atoi(chrlst[i]);//если digit с одним +/- приводим к типу int с помощью atoi
			new_node = init_stack_node(number);//Возможно, нужен вывод ошибки, если элемент не создался 
			if (ft_isduplicate(stack, number))//Проверка на дубли при добавлении в стэк нового элемента
			{
				write(2, "Error\n", 6);
				return(free_array(chrlst), NULL); //!!!НУЖНА еще фукнция очистки stack
			}
			add_new_node_last(&stack, new_node);
			i++;
		}
		free_array(chrlst);//Не накапливается, сразу очищаем
		index++;
	}
	print_stack(stack);//для тестирования
	return (stack);
}

void    print_stack(t_stack *stack)//только для тестирования
{
	if (!stack)
	{
		printf("Empty stack");
	}
	while (stack != NULL)
	{
		printf("Index: %d -> Value: %d\n", stack->index, stack->value);
		stack = stack->next;
	}
}

void	free_array(char **arg)
{
	int	i;

	if (!arg)
		return ;
	i = 0;
	while (arg[i] != NULL)
	{
		free(arg[i]);//Очищает массив
		i++;
	}
	free(arg);
}
