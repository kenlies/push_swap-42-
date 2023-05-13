/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parse_extra_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/01 07:12:29 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_checker_bonus.h"

char	*remove_leading_zeros_append(char *str, char *new, int i, int len)
{
	int	j;

	j = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		new[j++] = str[0];
		i--;
		len--;
	}
	while (j < len - i + 1)
	{
		new[j] = str[j + i];
		j++;
	}
	new[len - i] = '\0';
	return (new);
}

char	*remove_leading_zeros(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	j = 0;
	len = 0;
	while ((str[i] == '0' || str[i] == '-' || str[i] == '+')
		&& str[i + 1] != '\0')
		i++;
	len = ft_strlen(str);
	if (str[0] == '-' || str[0] == '+')
		len++;
	new = (char *)malloc(sizeof(char) * len - i + 1);
	if (!new)
		return (NULL);
	return (remove_leading_zeros_append(str, new, i, len));
}

void	free_new(char **new)
{
	int	i;

	i = 0;
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
}

void	add_elem(t_list **head, char **new)
{
	t_list	*tmp;
	int		*p;

	while (*new)
	{	
		p = (int *)malloc(sizeof(int));
		if (!p)
			return ;
		*p = ft_atoi(*new);
		tmp = ft_lstnew(p);
		if (!tmp)
			return ;
		ft_lstadd_back(head, tmp);
		new++;
	}
}

void	errors(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
