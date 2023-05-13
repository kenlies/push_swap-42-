/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/28 03:01:58 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_one(t_list **head_a)
{
	if (*(int *)(*head_a)->nxt->nxt->con > *(int *)(*head_a)->con
		&& *(int *)(*head_a)->con > *(int *)(*head_a)->nxt->con)
	{
		swap(head_a);
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	case_two(t_list **head_a)
{
	if (*(int *)(*head_a)->con > *(int *)(*head_a)->nxt->con
		&& *(int *)(*head_a)->nxt->con > *(int *)(*head_a)->nxt->nxt->con)
	{
		swap(head_a);
		ft_printf("sa\n");
		rev_rotate(head_a);
		ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	case_three(t_list **head_a)
{
	if (*(int *)(*head_a)->con > *(int *)(*head_a)->nxt->nxt->con
		&& *(int *)(*head_a)->nxt->nxt->con > *(int *)(*head_a)->nxt->con)
	{
		rotate(head_a);
		ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	case_four(t_list **head_a)
{
	if (*(int *)(*head_a)->nxt->con > *(int *)(*head_a)->nxt->nxt->con
		&& *(int *)(*head_a)->nxt->nxt->con > *(int *)(*head_a)->con)
	{
		swap(head_a);
		ft_printf("sa\n");
		rotate(head_a);
		ft_printf("ra\n");
		return (1);
	}
	return (0);
}

int	case_five(t_list **head_a)
{
	if (*(int *)(*head_a)->nxt->con > *(int *)(*head_a)->con
		&& *(int *)(*head_a)->con > *(int *)(*head_a)->nxt->nxt->con)
	{
		rev_rotate(head_a);
		ft_printf("rra\n");
		return (1);
	}
	return (0);
}
