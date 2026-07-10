/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkondak <olkondak@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:09:45 by olkondak          #+#    #+#             */
/*   Updated: 2026/07/10 14:15:17 by olkondak         ###   ########.fr       */
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
		free(head);
		head = tmp;
	}
}

int main(int argc, char **argv)
{
	t_stack	*head = NULL;
	t_stack	*new_node = NULL;
	int		i;	

	i = 1;
	if (argc == 3)
	{
		while (i < 3)
		{
			new_node = create_new_node(ft_atoi(argv[i]));
			if (new_node != NULL)
				add_new_node(&head, new_node);
			else
				return (1); //to handle malloc issues... 
			printf("Node [%d] is created\n", i);
			i++;
		}	
		print_nodes(head);
	}
	if (head != NULL)
	{
		printf("Cleaning something...");
		free_stack(head);
	}	
	return (0);
}
