/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_runner_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/06 07:49:12 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_checker_bonus.h"

int	parse_line(char *line)
{
	const char	*insts[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(line, (char *)insts[i]))
			return (1);
		i++;
	}
	return (0);
}

void	execute(t_list **head_a, t_list **head_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		swap(head_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(head_b);
	else if (!ft_strcmp(line, "pa\n"))
		push(head_b, head_a);
	else if (!ft_strcmp(line, "pb\n"))
		push(head_a, head_b);
	else if (!ft_strcmp(line, "ra\n"))
		rotate(head_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(head_b);
	else if (!ft_strcmp(line, "rra\n"))
		rev_rotate(head_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rev_rotate(head_b);
}

void	execute_doubles(t_list **head_a, t_list **head_b, char *line)
{
	if (!ft_strcmp(line, "ss\n"))
	{
		swap(head_a);
		swap(head_b);
	}
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotate(head_a);
		rotate(head_b);
	}
	else if (!ft_strcmp(line, "rrr\n"))
	{
		rev_rotate(head_a);
		rev_rotate(head_b);
	}
}

void	final_mark(t_list **head_a, t_list **head_b)
{
	if (is_sorted(*head_a) && *head_b == NULL)
	{
		ft_printf("OK\n");
		exit(0);
	}
	else
	{
		ft_printf("KO\n");
		exit(0);
	}
}

void	checker_runner(t_list **head_a, t_list **head_b)
{
	char	*line;

	while (1)
	{	
		line = get_next_line(0);
		if (line == NULL || !ft_strcmp(line, "\n"))
			final_mark(head_a, head_b);
		if (!parse_line(line))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		execute(head_a, head_b, line);
		execute_doubles(head_a, head_b, line);
	}
}
