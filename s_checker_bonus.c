/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_checker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/01 06:56:10 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_checker_bonus.h"

void	init_stack_a(t_list **head, char **argv)
{
	t_list	*tmp;
	int		*p;

	while (*++argv)
	{	
		p = (int *)malloc(sizeof(int));
		if (!p)
			return ;
		*p = ft_atoi(*argv);
		tmp = ft_lstnew(p);
		if (!tmp)
			return ;
		ft_lstadd_back(head, tmp);
	}
}

char	**init_stack_a_array(t_list **head, char **argv)
{
	char	**new;

	new = ft_split(argv[1], ' ');
	if (!new)
		return (NULL);
	add_elem(head, new);
	return (new);
}

void	parse_one_arg(t_list **head, char **argv)
{
	char	**new;
	int		i;	

	new = init_stack_a_array(head, argv);
	if (!new)
		errors();
	i = 0;
	while (i < ft_strlen_array(new))
	{
		if (!is_valid_int(new[i]))
			errors();
		if (is_dublicate(ft_strlen_array(new), new, new[i], i))
			errors();
		if (is_overflow(new[i]))
			errors();
		i++;
	}
	free_new(new);
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

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		is_one_arg;

	if (argc > 1)
	{
		is_one_arg = parse_args(argc, argv);
		if (is_one_arg)
			parse_one_arg(&head_a, argv);
		else
			init_stack_a(&head_a, argv);
		checker_runner(&head_a, &head_b);
		exit(0);
	}
	else
		return (1);
	return (0);
}
