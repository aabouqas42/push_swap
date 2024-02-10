/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:28:21 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/10 17:03:22 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus/push_swap_bonus.h"

int	check_cmds(char *action)
{
	return (ft_strncmp(action, "sa", 2) == 0 && ft_strlen(action) == 3
		|| ft_strncmp(action, "sb", 2) == 0 && ft_strlen(action) == 3
		|| ft_strncmp(action, "ss", 2) == 0 && ft_strlen(action) == 3
		|| ft_strncmp(action, "pa", 2) == 0 && ft_strlen(action) == 3
		|| ft_strncmp(action, "pb", 2) == 0 && ft_strlen(action) == 3
		|| ft_strncmp(action, "ra", 2) == 0 && ft_strlen(action) == 3
		|| ft_strncmp(action, "rb", 2) == 0 && ft_strlen(action) == 3
		|| ft_strncmp(action, "rr", 2) == 0 && ft_strlen(action) == 3
		|| ft_strncmp(action, "rra", 3) == 0 && ft_strlen(action) == 4
		|| ft_strncmp(action, "rrb", 3) == 0 && ft_strlen(action) == 4
		|| ft_strncmp(action, "rrr", 3) == 0 && ft_strlen(action) == 4
	);
}

void	execute_actions(t_data *data, char *action)
{
	if (ft_strncmp(action, "sa", 2) == 0)
		_sa_(data);
	if (ft_strncmp(action, "sb", 2) == 0)
		_sb_(data);
	if (ft_strncmp(action, "ss", 2) == 0)
		_ss_(data);
	if (ft_strncmp(action, "pa", 2) == 0)
		_pa_(data);
	if (ft_strncmp(action, "pb", 2) == 0)
		_pb_(data);
	if (ft_strncmp(action, "ra", 2) == 0)
		_ra_(data);
	if (ft_strncmp(action, "rb", 2) == 0)
		_rb_(data);
	if (ft_strncmp(action, "rr", 2) == 0)
		_rr_(data);
	if (ft_strncmp(action, "rra", 3) == 0)
		_rra_(data);
	if (ft_strncmp(action, "rrb", 3) == 0)
		_rrb_(data);
	if (ft_strncmp(action, "rrr", 3) == 0)
		_rrr_(data);
}

void	_checker(t_data *data)
{
	char	*action;

	action = get_next_line(STDIN_FILENO);
	while (action)
	{
		if (check_cmds(action))
		{
			execute_actions(data, action);
			free(action);
		}
		else
		{
			free (action);
			free_stack(data->stack_b);
			show_msg(data, "Error\n", -1);
		}
		action = get_next_line(STDIN_FILENO);
	}
}

int	main(int ac, char *av[])
{
	t_data	data;

	mem_free(data.input);
	data.stack_a = NULL;
	data.input = get_stack(av);
	check_input(&data);
	init_stack(&data);
	if (stack_len(data.stack_a) < (ac - 1))
		show_msg(&data, "Error\n", -1);
	if (stack_len(data.stack_a) == 1)
		show_msg(&data, "", 0);
	is_sorted(&data);
	_checker(&data);
	if (sorted(data.stack_a) && data.stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		(ft_putstr_fd("KO\n", 2), free_stack(data.stack_b));
	free_stack(data.stack_a);
	mem_free(data.input);
}
