/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/10 12:07:18 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	handle_specific_cases(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) >= 5)
	{
		push(head_a, head_b);
		push(head_a, head_b);
		ft_printf("pb\n");
		ft_printf("pb\n");
	}
	else if (ft_lstsize(*head_a) == 4)
	{
		push(head_a, head_b);
		ft_printf("pb\n");
	}
	else if (ft_lstsize(*head_a) == 2)
	{			
		swap(head_a);
		ft_printf("sa\n");
		exit(0);
	}
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
// couldn't have a variable for ft_strlen_array, 
// because of stupid norm (too many lines) >:c

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
		if (is_sorted(head_a))
			exit(0);
		handle_specific_cases(&head_a, &head_b);
		runner(&head_a, &head_b);
		exit(0);
	}
	else
		return (1);
	return (0);
}
