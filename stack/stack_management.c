/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvalk <mvalk@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 13:46:17 by mvalk         #+#    #+#                 */
/*   Updated: 2023/04/19 14:13:55 by mvalk         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_index(t_stack **a)
{
	t_stack	*tmp;
	int		index;

	tmp = *a;
	index = 0;
	while (tmp != NULL)
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}

int	ft_stack_size(t_stack *start)
{
	int	size;

	size = 0;
	while (start != NULL)
	{
		size++;
		start = start->next;
	}
	return (size);
}

void	ft_delstack(t_stack *node)
{
	if (node->prev && node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node = NULL;
	free (node);
}

void	free_list(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = *head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free (tmp);
		tmp = next;
	}
	*head = NULL;
}
