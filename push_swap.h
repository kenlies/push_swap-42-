/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:48 by aotsala           #+#    #+#             */
/*   Updated: 2023/05/10 12:07:08 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_info{
	int	pos;
	int	ops;
	int	a_rot;
	int	b_rot;
	int	a_rev_rot;
	int	b_rev_rot;
	int	ab_rot;
	int	ab_rev_rot;
	int	a_rotate;
	int	b_rotate;
	int	a_rev_rotate;
	int	b_rev_rotate;
	int	ab_rotate;
	int	ab_rev_rotate;
	int	reset;
	int	phase_two;
}			t_info;

void	init_stack_a(t_list **head, char **argv);
char	**init_stack_a_array(t_list **head, char **argv);
void	handle_specific_cases(t_list **head_a, t_list **head_b);
void	parse_one_arg(t_list **head, char **argv);
int		main(int argc, char **argv);

int		is_valid_one_arg(char **argv);
int		is_valid_int(char *str);
int		is_dublicate(int argc, char **argv, char *str, int blind);
int		is_overflow(char *str);
int		parse_args(int argc, char **argv);

void	errors(void);
int		is_sorted(t_list *head);
void	prints(t_info info);
void	init_info(t_info *info);
void	partial_reset(t_info *info);

void	swap(t_list **head);
void	push(t_list **head_from, t_list **head_to);
void	rotate(t_list **head);
void	rev_rotate(t_list **head);
int		abs(int n);

int		lst_find_bel(t_list *head, int num);
int		lst_find_below_throwback(t_list *head, int num);
int		lst_find_max(t_list *head);
int		lst_find_min(t_list *head);;
int		is_smallest_biggest(t_list *head_A, t_list *head_B);

int		case_one(t_list **head_a);
int		case_two(t_list **head_a);
int		case_three(t_list **head_a);
int		case_four(t_list **head_a);
int		case_five(t_list **head_a);

void	final_rotate(t_list **head_A, t_info *info);
void	rot_top(t_list **head, int target, t_info *info);
void	rev_rot_top(t_list **head, int target, t_info *info);
void	rot_or_rrot(t_list **head, int target, t_info *info);

void	calc_rots(t_info *info);
void	calc_rev_rots(t_info *info);
void	calc_double_moves(t_info *info);

void	sort_three_in_place(t_list **head_A);
void	do_rots(t_info *info);
void	do_rev_rots(t_info *info);
void	do_double_moves(t_info *info);

int		is_lowest_op(t_info *info);
void	calc_runner(t_list **head_A, t_list **head_B, t_info *info);
void	do_runner(t_list **head_A, t_list **head_B, t_info *info);
void	runner(t_list **head_A, t_list **head_B);

char	*remove_leading_zeros_append(char *str, char *new, int i, int len);
char	*remove_leading_zeros(char *str);
void	check_overflow(long long num);
void	free_new(char **new);
void	add_elem(t_list **head, char **new);

#endif