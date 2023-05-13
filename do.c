/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/01 07:08:56 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rots(t_info *info)
{
	if (info->a_rot < info->b_rot)
	{
		info->ab_rotate = info->a_rot;
		info->b_rotate = abs(info->a_rot - info->b_rot);
		info->a_rotate = 0;
	}
	else if (info->a_rot > info->b_rot)
	{
		info->ab_rotate = info->b_rot;
		info->a_rotate = abs(info->a_rot - info->b_rot);
		info->b_rotate = 0;
	}
	else if (info->a_rot == info->b_rot)
	{
		info->ab_rotate = info->a_rot;
		info->a_rotate = 0;
		info->b_rotate = 0;
	}
}

void	do_rev_rots(t_info *info)
{
	if (info->a_rev_rot < info->b_rev_rot)
	{
		info->ab_rev_rotate = info->a_rev_rot;
		info->b_rev_rotate = abs(info->a_rev_rot - info->b_rev_rot);
		info->a_rev_rotate = 0;
	}
	else if (info->a_rev_rot > info->b_rev_rot)
	{
		info->ab_rev_rotate = info->b_rev_rot;
		info->a_rev_rotate = abs(info->a_rev_rot - info->b_rev_rot);
		info->b_rev_rotate = 0;
	}
	else if (info->a_rev_rot == info->b_rev_rot)
	{
		info->ab_rev_rotate = info->a_rev_rot;
		info->a_rev_rotate = 0;
		info->b_rev_rotate = 0;
	}
}

void	do_double_moves(t_info *info)
{
	if (info->a_rot && info->b_rot)
		do_rots(info);
	else if (info->a_rev_rot && info->b_rev_rot)
		do_rev_rots(info);
}
