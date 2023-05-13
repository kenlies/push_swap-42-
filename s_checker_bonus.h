/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_checker_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/10 12:07:11 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CHECKER_BONUS_H
# define S_CHECKER_BONUS_H

# include "libft/libft.h"

void	init_stack_a(t_list **head, char **argv);
char	**init_stack_a_array(t_list **head, char **argv);
void	parse_one_arg(t_list **head, char **argv);
int		is_sorted(t_list *head);

int		is_valid_one_arg(char **argv);
int		is_valid_int(char *str);
int		is_dublicate(int argc, char **argv, char *str, int blind);
int		is_overflow(char *str);
int		parse_args(int argc, char **argv);

char	*remove_leading_zeros_append(char *str, char *new, int i, int len);
char	*remove_leading_zeros(char *str);
void	free_new(char **new);
void	add_elem(t_list **head, char **new);
void	errors(void);

void	swap(t_list **head);
void	push(t_list **head_from, t_list **head_to);
void	rotate(t_list **head);
void	rev_rotate(t_list **head);

int		parse_line(char *line);
void	execute(t_list **head_a, t_list **head_b, char *line);
void	execute_doubles(t_list **head_a, t_list **head_b, char *line);
void	final_mark(t_list **head_a, t_list **head_b);
void	checker_runner(t_list **head_a, t_list **head_b);

#endif