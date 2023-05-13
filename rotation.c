/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/30 01:50:15 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_list **head_A, t_info *info)
{
	rot_or_rrot(head_A, lst_find_min(*head_A), info);
	while (info->b_rot--)
	{
		rotate(head_A);
		ft_printf("ra\n");
	}
	while (info->b_rev_rot--)
	{
		rev_rotate(head_A);
		ft_printf("rra\n");
	}
}

void	rot_top(t_list **head, int target, t_info *info)
{
	t_list	*tmp;

	tmp = *head;
	while (*(int *)tmp->con != target)
	{
		info->b_rot++;
		tmp = tmp->nxt;
	}
}

void	rev_rot_top(t_list **head, int target, t_info *info)
{
	t_list	*tmp;

	tmp = *head;
	while (*(int *)tmp->con != target)
	{
		info->b_rev_rot++;
		tmp = tmp->nxt;
	}
	info->b_rev_rot = ft_lstsize(*head) - info->b_rev_rot;
}

void	rot_or_rrot(t_list **head, int target, t_info *info)
{
	int		pos;
	int		lst_size;
	t_list	*tmp;

	pos = 1;
	lst_size = ft_lstsize(*head);
	tmp = *head;
	while (tmp)
	{
		if (*(int *)tmp->con == target)
		{
			if (((pos - 1) <= (lst_size - pos + 1)) && (pos != 1))
			{
				rot_top(head, target, info);
				return ;
			}
			else if ((pos - 1) > (lst_size - pos + 1))
			{
				rev_rot_top(head, target, info);
				return ;
			}
		}		
		tmp = tmp->nxt;
		pos++;
	}
}
// left_dist to head: "pos - 1"
// right_dist to head: "lst_size - pos + 1"
