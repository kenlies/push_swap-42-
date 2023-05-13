/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/10 12:08:04 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_one_arg(char **argv)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (argv[2])
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			k++;
		i++;
	}
	if (k && argv[1][k] == '\0')
		errors();
	return (1);
}

int	is_valid_int(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] != '-' && !ft_isdigit(str[i]) && str[i] != '+')
			return (0);
		if (str[i] == '-' || str[i] == '+')
			sign++;
		i++;
		if (sign > 1)
			return (0);
	}
	return (1);
}

int	is_dublicate(int argc, char **argv, char *str, int blind)
{
	int		i;
	char	*new;

	if (!ft_strcmp(argv[0], "./push_swap"))
		i = 1;
	else
		i = 0;
	new = remove_leading_zeros(str);
	if (!new)
		return (1);
	while (i < argc)
	{
		if (i == blind)
		{
			i++;
			continue ;
		}
		if (!ft_strcmp(new, argv[i++]))
		{
			free(new);
			return (1);
		}
	}
	free(new);
	return (0);
}

int	is_overflow(char *str)
{
	char	*new;

	new = remove_leading_zeros(str);
	if (!new)
		return (1);
	if (ft_strcmp(new, "0") && ft_strcmp(new, "-1"))
	{
		if (ft_atoi(new) == 0 || ft_atoi(new) == -1)
		{
			free(new);
			return (1);
		}
	}
	free(new);
	return (0);
}

int	parse_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (is_valid_one_arg(argv))
		return (1);
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
			errors();
		if (is_dublicate(argc, argv, argv[i], i))
			errors();
		if (is_overflow(argv[i]))
			errors();
		i++;
	}
	return (0);
}
