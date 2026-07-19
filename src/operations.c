/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkondak <olkondak@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:17:42 by olkondak          #+#    #+#             */
/*   Updated: 2026/07/19 21:26:49 by olkondak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//sa (swap a): Swap the first two elements at the top of stack a.
//Do nothing if there is only one or no elements. 

typedef struct s_stack {
	int		value;
	int		index;
	struct	s_stack	*next;
}	t_stack;

void	swap(t_stack **head);
/*static int	count_nodes(t_stack *head)
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
}*/

void	sa(t_stack **head)
{
	if (!head || !*head)
		return ;
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_stack **head)
{
	if (!head || !*head)
		return ;
	swap(head);
	write(1, "sb\n", 3);
}

void	ss(t_stack **head_a, t_stack **head_b)
{
	if (!head_a || !head_b || !*head_a || !*head_b)
		return ;
	swap(head_a);
	swap(head_b);
	write(1, "ss\n", 3);
}

void    swap(t_stack **head)
{
    t_stack *first;
    t_stack *second;

    if (!head || !*head || !(*head)->next)
        return ;
    first = *head; //first holds the address of the first node
    second = first->next; //second holds the address of the next, (i.e.second) node
    first->next = second->next; //first->next becomes what used to be next address of the second node
    second->next = *head; //second->next points to the original head (i.e.first node);  
    *head = second; //the "head" is modified to have a value of a second node 
}

void	push(t_stack **head_src, t_stack **head_dst)
{
	t_stack	*tmp;

	if (!head_src || !*head_src || !head_dst)
		return ;
	//Copying the source data into a tmp
	tmp = *head_src;
	//"Removing" the node from the source, by pointing the head to the ->next
	*head_src = (*head_src)->next;
	//Modifying the destination stack
	//works for both if destination is NULL or not NULL.
	//Initially I wrote the code below with (*head_dst)->next = *head_dst
	//which resulted in segmentation fault error for head_dst = NULL
	//because NULL->next = NULL - is not valid
	//AI suggested to reuse tmp->next (re-assing tmp->next to a new value)
	//At this point we do not care what tmp->next was before, therefore we can overwrite it. 
	tmp->next = *head_dst;
	*head_dst = tmp;
}
