/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/30 01:49:26 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_rots(t_info *info)
{
	t_info	tmp;

	tmp = *info;
	if (tmp.a_rot < tmp.b_rot)
	{
		tmp.ab_rot = tmp.a_rot;
		tmp.b_rot = abs(tmp.a_rot - tmp.b_rot);
		tmp.a_rot = 0;
	}
	else if (tmp.a_rot > tmp.b_rot)
	{
		tmp.ab_rot = tmp.b_rot;
		tmp.a_rot = abs(tmp.a_rot - tmp.b_rot);
		tmp.b_rot = 0;
	}
	else if (tmp.a_rot == tmp.b_rot)
	{
		tmp.ab_rot = tmp.a_rot;
		tmp.a_rot = 0;
		tmp.b_rot = 0;
	}
	info->ops += tmp.ab_rot;
	info->ops += tmp.a_rot + tmp.b_rot;
}

void	calc_rev_rots(t_info *info)
{
	t_info	tmp;

	tmp = *info;
	if (tmp.a_rev_rot < tmp.b_rev_rot)
	{
		tmp.ab_rev_rot = tmp.a_rev_rot;
		tmp.b_rev_rot = abs(tmp.a_rev_rot - tmp.b_rev_rot);
		tmp.a_rev_rot = 0;
	}
	else if (tmp.a_rev_rot > tmp.b_rev_rot)
	{
		tmp.ab_rev_rot = tmp.b_rev_rot;
		tmp.a_rev_rot = abs(tmp.a_rev_rot - tmp.b_rev_rot);
		tmp.b_rev_rot = 0;
	}
	else if (tmp.a_rev_rot == tmp.b_rev_rot)
	{
		tmp.ab_rev_rot = tmp.a_rev_rot;
		tmp.a_rev_rot = 0;
		tmp.b_rev_rot = 0;
	}
	info->ops += tmp.ab_rev_rot;
	info->ops += tmp.a_rev_rot + tmp.b_rev_rot;
}

void	calc_double_moves(t_info *info)
{
	if (info->a_rot && info->b_rot)
		calc_rots(info);
	else if (info->a_rev_rot && info->b_rev_rot)
		calc_rev_rots(info);
	else
	{
		info->ops += info->ab_rot + info->ab_rev_rot;
		info->ops += info->a_rot + info->b_rot;
		info->ops += info->a_rev_rot + info->b_rev_rot;
	}
}
