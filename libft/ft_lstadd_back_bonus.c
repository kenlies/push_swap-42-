/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 01:27:19 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/28 03:25:58 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			while (current->nxt)
				current = current->nxt;
			current->nxt = new;
		}
	}
}
