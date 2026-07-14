#include "push_swap.h"

t_stack *init_stack_node(int new_value)
{
    t_stack    *new_node; 

    new_node = malloc(sizeof(t_stack));//Выделение памяти под новый нод
    if (!new_node)//Возвращаем NULL, если неуспешно 
        return (NULL);
    new_node->value = new_value;//Присвоение переданного значения value в новом ноде
    new_node->index = 0;//Устанавливаем индекс по умолчанию 0
    new_node->next = NULL;//Ссылка на следующий нод NULL
    return (new_node);
}

void    add_new_node_last(t_stack **stack, t_stack *new_node)
{
    t_stack *last;

    if (stack && new_node)//Если оба значения не пустые
    {
	if (!*stack)//Проверка, существует ли stack, не равен ли NULL
        	*stack = new_node;//Если не существует, то в первый нод устанавливается созданный new_node
    	else
    	{
        	last = *stack;//Иначе присвоение нов пер. значение указателя на stack, чтобы с ним работать
        	while (last->next)//В цикле поиск последнего нода
            		last = last->next;
        	last->next = new_node;//Устанавливается связь с созданным выше new_node
    	}
    }
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_node;
	t_stack	*current;

	if (!*stack || !stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}
