/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:25:58 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/12 16:05:24 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	char	**input;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

t_stack	*creat_new_node(int number);
void	add_back(t_stack **head, t_stack *new_node);
void	add_front(t_stack **head, t_stack *new_node);
void	show_msg(t_data *data, char *msg, int ret);
void	free_tab(char **input);
void	free_stack(t_stack *stack);
char	**get_stack(char **inputs);
void	init_stack(t_data *data);
void	check_input(t_data *data);
void	is_sorted(t_data *data);
void	is_empty(char **argv);
int		_atoi(t_data *data, const char *str);
int		sorted(t_stack *data);
int		get_position(t_stack *stack, int number);
void	_sa_(t_data *data);
void	_sb_(t_data *data);
void	_ss_(t_data *data);
void	_pa_(t_data *data);
void	_pb_(t_data *data);
void	_ra_(t_data *data);
void	_rb_(t_data *data);
void	_rr_(t_data *data);
void	_rra_(t_data *data);
void	_rrb_(t_data *data);
void	_rrr_(t_data *data);
int		stack_len(t_stack *stack);
t_stack	*get_min(t_stack *stack);
t_stack	*get_max(t_stack *stack);
int		get_index(t_stack *stack, int number);
void	execute_instructions(t_data *data);

#endif
