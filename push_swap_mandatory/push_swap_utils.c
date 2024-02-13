/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 02:32:37 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/13 09:30:41 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_msg(t_data *data, char *msg, int ret)
{
	ft_putstr_fd(msg, 2);
	free_tab(data->input);
	free_stack(data->stack_a);
	exit(ret);
}

char	**get_stack(char **inputs)
{
	char	**input;
	char	*str;
	char	*temp;
	int		i;

	i = 1;
	str = NULL;
	while (inputs[i])
	{
		temp = ft_strjoin(str, inputs[i]);
		if (temp == NULL)
			(free (str), ft_putstr_fd("Error\n", 2), exit(-1));
		free (str);
		str = ft_strjoin(temp, " ");
		if (str == NULL)
			(free(temp), ft_putstr_fd("Error\n", 2), exit(-1));
		free (temp);
		i++;
	}
	input = ft_split(str, ' ');
	free(str);
	if (input == NULL)
		(ft_putstr_fd("Error\n", 2), exit(-1));
	return (input);
}

int	get_index(t_stack *list, int number)
{
	t_stack	*node;
	int		index;

	node = list;
	index = 0;
	while (node)
	{
		if (node->number < number)
			index++;
		node = node->next;
	}
	return (index);
}

void	init_stack(t_data *data)
{
	t_stack	*node;
	int		i;

	i = 0;
	data->stack_a = NULL;
	while (data->input[i])
	{
		node = creat_new_node(_atoi(data, data->input[i]));
		if (node == NULL)
			show_msg(data, "Error\n", -1);
		add_back(&data->stack_a, node);
		i++;
	}
	node = data->stack_a;
	while (node)
	{
		node->index = get_index(data->stack_a, node->number);
		node = node->next;
	}
}

int	_atoi(t_data *data, const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	sign = sign - (2 * (*str == '-'));
	if (*str == '+' || *str == '-')
		str++;
	if (str == NULL || *str == 0)
		show_msg(data, "Error\n", -1);
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			show_msg(data, "Error\n", -1);
		res = res * 10 + (*str - 48);
		if ((res > 2147483647 && sign == 1) || (res > 2147483648 && sign == -1))
			show_msg(data, "Error\n", -1);
		str++;
	}
	return (res * sign);
}
