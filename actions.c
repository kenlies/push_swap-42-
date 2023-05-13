/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/10 12:08:33 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*third;
	t_list	*first;

	if ((*head)->nxt == NULL)
		return ;
	first = (*head);
	(*head) = (*head)->nxt;
	third = (*head)->nxt;
	(*head)->nxt = first;
	first->nxt = third;
}

void	push(t_list **head_from, t_list **head_to)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *head_from;
	new = ft_lstnew((*head_from)->con);
	if (!new)
		return ;
	ft_lstadd_front(head_to, new);
	*head_from = (*head_from)->nxt;
	free(tmp);
}

void	rotate(t_list **head)
{	
	t_list	*tmp;

	tmp = *head;
	ft_lstadd_back(head, ft_lstnew((*head)->con));
	(*head) = (*head)->nxt;
	free((tmp));
}

void	rev_rotate(t_list **head)
{
	t_list	*last;
	t_list	*second_last;

	last = ft_lstlast(*head);
	second_last = *head;
	while (second_last->nxt != last)
		second_last = second_last->nxt;
	second_last->nxt = NULL;
	last->nxt = *head;
	*head = last;
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
