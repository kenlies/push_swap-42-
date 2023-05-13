/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_actions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/10 15:16:55 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_checker_bonus.h"

void	swap(t_list **head)
{
	t_list	*third;
	t_list	*first;

	if (ft_lstsize(*head) == 1 || ft_lstsize(*head) == 0)
		return ;
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

	if (ft_lstsize(*head_from) == 0)
		return ;
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
	if (ft_lstsize(*head) == 1 || ft_lstsize(*head) == 0)
		return ;
	ft_lstadd_back(head, ft_lstnew((*head)->con));
	(*head) = (*head)->nxt;
	free((tmp));
}

void	rev_rotate(t_list **head)
{
	t_list	*last;
	t_list	*second_last;

	if (ft_lstsize(*head) == 1 || ft_lstsize(*head) == 0)
		return ;
	last = ft_lstlast(*head);
	second_last = *head;
	while (second_last->nxt != last)
		second_last = second_last->nxt;
	second_last->nxt = NULL;
	last->nxt = *head;
	*head = last;
}
