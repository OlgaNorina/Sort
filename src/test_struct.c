/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkondak <olkondak@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:09:45 by olkondak          #+#    #+#             */
/*   Updated: 2026/07/20 21:59:40 by olkondak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr);

typedef struct s_stack {
	int		value;
	int		index;
	struct	s_stack	*next;
}	t_stack;

//this function is in operations.c
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ss(t_stack **head_a, t_stack **head_b);
void	pa(t_stack **head_b, t_stack **head_a);
void	pb(t_stack **head_a, t_stack **head_b);
void    ra(t_stack **head_a);
void	rb(t_stack **head_b);
void    rr(t_stack **head_a, t_stack **head_b);
void    rra(t_stack **head_a);
void	rrb(t_stack **head_b);
void	rrr(t_stack **head_a, t_stack **head_b);

//Function to create a new "node/item" of type t_stack
//Single node, not connected/linked to the others
static t_stack	*create_new_node(int value)
{
	t_stack	*new_node;
	
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

static void	add_new_node(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
 	tmp->next = new_node;	
}

//Just for the testing purpose:
//Function to print the "content" of our nodes. 
static void	print_nodes(t_stack *head)
{
	t_stack	*tmp;
	
	tmp = head;
	while (tmp != NULL)
	{
		printf("value -> %d, index -> %d, next -> %p\n", tmp->value, tmp->index, tmp->next);
		tmp = tmp->next;
	}
}

static void	free_stack(t_stack *head)
{
	t_stack	*tmp;
	
	while (head != NULL)
	{
		tmp = head->next;
		free(head); //maybe also there is need to not only free, but also clean the data itself
		head = tmp;
	}
}

int main(int argc, char **argv)
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;
	t_stack	*new_node = NULL;
	int		i;

	i = 1;
	while (i < argc)
	{
		new_node = create_new_node(ft_atoi(argv[i]));
		if (new_node != NULL)
			add_new_node(&stack_a, new_node);
		else
			return (1); //to handle malloc issues... 
		printf("Node [%d] is created\n", i);
		i++;
	}
	printf("Printing stack_a:\n");	
	printf("-----------------\n");
	print_nodes(stack_a);
	printf("-----------------\n");

	printf("head value before is %p\n", stack_a);

	//To test any of the interface functions:
	//sa(&stack_a);
	//sb(&stack_b);
	//ss(&stack_a, &stack_b);
	//pb(&stack_a, &stack_b);
	rrr(&stack_a, &stack_b);

			
	printf("Printing stack_a:\n");
	printf("-----------------\n");
	print_nodes(stack_a);
	printf("-----------------\n");
	printf("Printing stack_b:\n");
	printf("-----------------\n");
	print_nodes(stack_b);
	printf("-----------------\n");
	
	if (stack_a != NULL)
	{
		printf("Cleaning stack_a...");
		free_stack(stack_a);
	}	
	if (stack_b != NULL)
	{
		printf("Cleaning stack_b...");
		free_stack(stack_b);
	}
	return (0);	
}
