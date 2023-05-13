/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/10 12:08:58 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_lowest_op(t_info *info)
{
	static int	lowest_op = 2147483647;

	calc_double_moves(info);
	if (info->reset)
	{
		lowest_op = 2147483647;
		info->reset = 0;
	}
	if (info->ops < lowest_op)
	{
		lowest_op = info->ops;
		info->a_rotate = info->a_rot;
		info->b_rotate = info->b_rot;
		info->a_rev_rotate = info->a_rev_rot;
		info->b_rev_rotate = info->b_rev_rot;
		info->ab_rotate = info->ab_rot;
		info->ab_rev_rotate = info->ab_rev_rot;
		do_double_moves(info);
		return (1);
	}
	return (0);
}

void	calc_runner(t_list **head_a, t_list **head_b, t_info *info)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	float	lst_size;

	tmp_a = *head_a;
	tmp_b = *head_b;
	lst_size = (float)ft_lstsize(tmp_a);
	while (tmp_a)
	{
		if (is_smallest_biggest(tmp_a, tmp_b))
			rot_or_rrot(&tmp_b, lst_find_max(tmp_b), info);
		else
			rot_or_rrot(&tmp_b, lst_find_bel(tmp_b, *(int *)tmp_a->con), info);
		if (((info->pos - 1) <= (lst_size - info->pos + 1)) && info->pos != 1)
			info->a_rot++;
		else if ((info->pos - 1) > (lst_size - info->pos + 1))
		{
			info->a_rot = 0;
			info->a_rev_rot = (lst_size - info->pos + 1);
		}
		is_lowest_op(info);
		partial_reset(info);
		info->pos++;
		tmp_a = tmp_a->nxt;
	}
}
// left_dist to head: "pos - 1"
// right_dist to head: "lst_size - pos + 1"

void	do_runner(t_list **head_a, t_list **head_b, t_info *info)
{
	prints(*info);
	while (info->a_rotate--)
		rotate(head_a);
	while (info->b_rotate--)
		rotate(head_b);
	while (info->a_rev_rotate--)
		rev_rotate(head_a);
	while (info->b_rev_rotate--)
		rev_rotate(head_b);
	while (info->ab_rotate--)
	{
		rotate(head_a);
		rotate(head_b);
	}
	while (info->ab_rev_rotate--)
	{
		rev_rotate(head_a);
		rev_rotate(head_b);
	}
	push(head_a, head_b);
	ft_printf("pb\n");
	init_info(info);
}

void	throwback_runner(t_list **head_a, t_list **head_b, t_info *info)
{
	while (ft_lstsize(*head_b))
	{
		if (is_smallest_biggest(*head_b, *head_a))
			rot_or_rrot(head_a, lst_find_min(*head_a), info);
		else
		{
			rot_or_rrot(head_a, lst_find_below_throwback
				(*head_a, *(int *)(*head_b)->con), info);
		}
		while (info->b_rot--)
		{
			rotate(head_a);
			ft_printf("ra\n");
		}
		while (info->b_rev_rot--)
		{
			rev_rotate(head_a);
			ft_printf("rra\n");
		}
		push(head_b, head_a);
		ft_printf("pa\n");
		partial_reset(info);
	}
}

void	runner(t_list **head_a, t_list **head_b)
{
	t_info	info;

	init_info(&info);
	while (!is_sorted(*head_a) || ft_lstsize(*head_b))
	{
		if (ft_lstsize(*head_a) == 3)
		{
			sort_three_in_place(head_a);
			if (ft_lstsize(*head_b))
				info.phase_two = 1;
		}
		if (info.phase_two)
		{
			throwback_runner(head_a, head_b, &info);
			final_rotate(head_a, &info);
			info.phase_two = 0;
		}
		else if (ft_lstsize(*head_b))
		{
			calc_runner(head_a, head_b, &info);
			do_runner(head_a, head_b, &info);
		}
	}
}
