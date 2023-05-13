/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/01 07:10:38 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_in_place(t_list **head_a)
{
	if (case_one(head_a))
		return ;
	else if (case_two(head_a))
		return ;
	else if (case_three(head_a))
		return ;
	else if (case_four(head_a))
		return ;
	else if (case_five(head_a))
		return ;
}

int	is_sorted(t_list *head)
{
	while (head && head->nxt)
	{
		if (*(int *)head->con > *(int *)head->nxt->con)
			return (0);
		head = head->nxt;
	}
	return (1);
}

void	prints(t_info info)
{
	while (info.a_rotate--)
		ft_printf("ra\n");
	while (info.b_rotate--)
		ft_printf("rb\n");
	while (info.a_rev_rotate--)
		ft_printf("rra\n");
	while (info.b_rev_rotate--)
		ft_printf("rrb\n");
	while (info.ab_rotate--)
		ft_printf("rr\n");
	while (info.ab_rev_rotate--)
		ft_printf("rrr\n");
}

void	init_info(t_info *info)
{
	ft_bzero(info, sizeof(*info));
	info->ops = 1;
	info->pos = 1;
	info->reset = 1;
}

void	partial_reset(t_info *info)
{
	info->ops = 1;
	info->ab_rot = 0;
	info->ab_rev_rot = 0;
	info->b_rot = 0;
	info->b_rev_rot = 0;
}
