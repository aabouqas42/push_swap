/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_manager_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:04:46 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/12 14:18:36 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_cmds(char *action)
{
	return ((ft_strncmp(action, "sa", 2) == 0 && ft_strlen(action) == 3)
		|| (ft_strncmp(action, "sb", 2) == 0 && ft_strlen(action) == 3)
		|| (ft_strncmp(action, "ss", 2) == 0 && ft_strlen(action) == 3)
		|| (ft_strncmp(action, "pa", 2) == 0 && ft_strlen(action) == 3)
		|| (ft_strncmp(action, "pb", 2) == 0 && ft_strlen(action) == 3)
		|| (ft_strncmp(action, "ra", 2) == 0 && ft_strlen(action) == 3)
		|| (ft_strncmp(action, "rb", 2) == 0 && ft_strlen(action) == 3)
		|| (ft_strncmp(action, "rr", 2) == 0 && ft_strlen(action) == 3)
		|| (ft_strncmp(action, "rra", 3) == 0 && ft_strlen(action) == 4)
		|| (ft_strncmp(action, "rrb", 3) == 0 && ft_strlen(action) == 4)
		|| (ft_strncmp(action, "rrr", 3) == 0 && ft_strlen(action) == 4)
	);
}

char	*get_instracions_str(t_data *data)
{
	char	*action;
	char	*temp;
	char	*str;

	action = get_next_line(STDIN_FILENO);
	str = NULL;
	temp = NULL;
	while (action)
	{
		if (check_cmds(action))
		{
			temp = ft_strjoin(str, action);
			if (temp == NULL)
				(free (str), free (action), show_msg(data, "Error\n", -1));
			free (str);
			str = ft_strjoin(temp, "");
			if (str == NULL)
				(free (temp), free (action), show_msg(data, "Error\n", -1));
			(free (temp), free(action));
		}
		else
			(free (action), free (str), show_msg(data, "Error\n", -1));
		action = get_next_line(STDIN_FILENO);
	}
	return (str);
}

char	**get_instractions_array(char *ins)
{
	char	**instructions;

	instructions = ft_split(ins, '\n');
	return (instructions);
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

void	execute_instructions(t_data *data, char *actions)
{
	char	**instructions;
	int		i;

	instructions = get_instractions_array(actions);
	free (actions);
	i = 0;
	while (instructions[i])
	{
		execute_actions(data, instructions[i]);
		free (instructions[i]);
		i++;
	}
	free (instructions);
}
