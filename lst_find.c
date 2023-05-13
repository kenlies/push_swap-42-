/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/28 22:58:10 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_find_bel(t_list *head, int num)
{
	int		closest;
	int		value;
	t_list	*current;

	closest = -2147483648;
	current = head;
	while (current)
	{
		value = *(int *)(current->con);
		if (value < num && value > closest)
		{
			closest = value;
		}
		current = current->nxt;
	}
	return (closest);
}

int	lst_find_below_throwback(t_list *head, int num)
{
	int		closest;
	int		value;
	t_list	*current;

	closest = 2147483647;
	current = head;
	while (current)
	{
		value = *(int *)(current->con);
		if (value > num && value < closest)
		{
			closest = value;
		}
		current = current->nxt;
	}
	return (closest);
}

int	lst_find_max(t_list *head)
{
	int	max;

	max = 0;
	if (head == NULL)
		return (0);
	max = *(int *)head->con;
	while (head)
	{
		if (*(int *)head->con > max)
			max = *(int *)head->con;
		head = head->nxt;
	}
	return (max);
}

int	lst_find_min(t_list *head)
{
	int	min;

	min = 0;
	if (head == NULL)
		return (0);
	min = *(int *)head->con;
	while (head)
	{
		if (*(int *)head->con < min)
			min = *(int *)head->con;
		head = head->nxt;
	}
	return (min);
}

int	is_smallest_biggest(t_list *head_A, t_list *head_B)
{
	if (*(int *)head_A->con > lst_find_max(head_B))
		return (1);
	else if (*(int *)head_A->con < lst_find_min(head_B))
		return (1);
	return (0);
}
