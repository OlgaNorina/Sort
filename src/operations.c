/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkondak <olkondak@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:17:42 by olkondak          #+#    #+#             */
/*   Updated: 2026/07/16 21:18:51 by olkondak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//sa (swap a): Swap the first two elements at the top of stack a.
//Do nothing if there is only one or no elements. 

typedef struct s_stack {
	int		value;
	int		index;
	struct	s_stack	*next;
}	t_stack;

static int	count_nodes(t_stack *head)
{
	int		count;

	if (head == NULL)
		return (0);
	count = 0;
	while (head != NULL)
	{
		count = count + 1;
		head = head->next;
	}
	return (count);
}

void	sa(t_stack **head)
{
	int		count;
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack *tmp_next_b;
	
	count = count_nodes(*head);
	printf("amount of nodes - %d\n", count);
	if (count > 1)
	{
		tmp_b = (*head)->next; //address of b; putting () to avoid operator precedence
		printf("tmp_b is %p\n", tmp_b);
		tmp_next_b = tmp_b->next; //address of the node after b
		printf("tmp_next_b is %p\n", tmp_next_b);
		tmp_a = *head; //address of a
		printf("tmp_a is %p\n", tmp_a);
		
		*head = tmp_b; //the first node receives the address of b
		printf("head is %p\n", *head);
		(*head)->next = tmp_a; //->next becomes the address of a
		printf("head->next is %p\n", (*head)->next);
		(*head)->next->next = tmp_next_b; //the second node (a) links to the address that used to be in b->next (can be NULL if there are only 2 nodes
		printf("head->next->next is %p\n", (*head)->next->next);
	}
	
}
