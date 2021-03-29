/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		display_result(t_data *data)
{
	int i;

	if (already_in_order(data) > 0)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	i = 0;
	while (i < data->len_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
		{
			write(1, "KO\n", 3);
			return (-1);
		}
		i++;
	}
	if (data->len_b == 0)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	write(1, "KO\n", 3);
	return (0);
}

void	get_instruc(t_data *data, char **instruct, int i)
{
	if (!ft_strncmp(instruct[i], "sa", 3))
		sa(data);
	else if (!ft_strncmp(instruct[i], "sb", 3))
		sb(data);
	else if (!ft_strncmp(instruct[i], "ss", 3))
		ss(data);
	else if (!ft_strncmp(instruct[i], "pa", 3))
		pa(data);
	else if (!ft_strncmp(instruct[i], "pb", 3))
		pb(data);
	else if (!ft_strncmp(instruct[i], "ra", 3))
		ra(data);
	else if (!ft_strncmp(instruct[i], "rb", 3))
		rb(data);
	else if (!ft_strncmp(instruct[i], "rr", 3))
		rr(data);
	else if (!ft_strncmp(instruct[i], "rra", 4))
		rra(data);
	else if (!ft_strncmp(instruct[i], "rrb", 4))
		rrb(data);
	else if (!ft_strncmp(instruct[i], "rrr", 4))
		rrr(data);
}

int		exec_instruct(t_data *data)
{
	int		i;
	char	**instruct;

	instruct = ft_split(data->line, '\n');
	i = 0;
	while (instruct && instruct[i])
	{
		get_instruc(data, instruct, i);
		i++;
	}
	free_tab(instruct);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		instruct;
	char	*line;

	init_struct(&data, argc, argv);
	if (check(&data, argv, argc) < 0)
		return (0);
	if (parse(&data, argv, argc) < 0)
		return (free_all(&data));
	if (already_in_order(&data) > 0)
		return (free_all(&data));
	while (1)
	{
		instruct = get_next_line(0, &line);
		data.line = ft_strjoin(data.line, line);
		data.line = ft_strjoin_free_first(data.line, "\n");
		free(line);
		if (instruct == 0)
			break ;
	}
	exec_instruct(&data);
	if (!ft_strncmp(argv[1], "-v", 2))
		debug(&data);
	display_result(&data);
	free_all(&data);
	return (0);
}
