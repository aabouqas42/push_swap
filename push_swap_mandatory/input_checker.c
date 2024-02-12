/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:57:07 by aabouqas          #+#    #+#             */
/*   Updated: 2024/02/12 11:51:02 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(t_data *data)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (data->input[i])
	{
		n = _atoi(data, data->input[i]);
		j = i + 1;
		while (data->input[j])
		{
			if (n == _atoi(data, data->input[j]))
				show_msg(data, "Error\n", -1);
			j++;
		}
		i++;
	}
}

void	is_sorted(t_data *data)
{
	char	**input;
	int		check;
	int		i;

	input = data->input;
	i = 1;
	check = 1;
	while (input[i])
	{
		if (_atoi(data, input[i]) > _atoi(data, input[i - 1]))
			check++;
		i++;
	}
	if (i == check)
		show_msg(data, "", 0);
}

void	is_empty(char **argv)
{
	char	*str;
	int		check;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		str = argv[i];
		j = 0;
		check = 0;
		while (str[j])
		{
			if (str[j] == ' ')
				check++;
			j++;
		}
		if (j == check)
			(ft_putstr_fd("Error\n", 2), exit(-1));
		i++;
	}
}
