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

int	display_result(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
		{
			write(1, "KO\n", 3);
			free_all(data);
			return (1);
		}
		i++;
	}
	if (data->len_b == 0)
	{
		write(1, "OK\n", 3);
		free_all(data);
		return (1);
	}
	write(1, "KO\n", 3);
	free_all(data);
	return (1);
}

int	print_error(t_data *data)
{
	free_all(data);
	write(2, "Error\n", 6);
	return (-1);
}

int	get_instruc(t_data *data, char **instruct, int i)
{
	if (!ft_strncmp(instruct[i], "sa", 3))
		return (sa(data));
	else if (!ft_strncmp(instruct[i], "sb", 3))
		return (sb(data));
	else if (!ft_strncmp(instruct[i], "ss", 3))
		return (ss(data));
	else if (!ft_strncmp(instruct[i], "pa", 3))
		return (pa(data));
	else if (!ft_strncmp(instruct[i], "pb", 3))
		return (pb(data));
	else if (!ft_strncmp(instruct[i], "ra", 3))
		return (ra(data));
	else if (!ft_strncmp(instruct[i], "rb", 3))
		return (rb(data));
	else if (!ft_strncmp(instruct[i], "rr", 3))
		return (rr(data));
	else if (!ft_strncmp(instruct[i], "rra", 4))
		return (rra(data));
	else if (!ft_strncmp(instruct[i], "rrb", 4))
		return (rrb(data));
	else if (!ft_strncmp(instruct[i], "rrr", 4))
		return (rrr(data));
	else
		return (print_error(data));
	return (1);
}

int	exec_instruct(t_data *data)
{
	int		i;
	char	**instruct;

	instruct = ft_split(data->line, '\n');
	i = 0;
	while (instruct && instruct[i])
	{
		if (get_instruc(data, instruct, i) < 0)
		{
			free_tab(instruct);
			return (-1);
		}
		i++;
	}
	free_tab(instruct);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		instruct;
	char	*line;

	init_struct(&data, argc, argv);
	if (check(&data, argv, argc) < 0)
		return (1);
	if (parse(&data, argv) < 0)
		return (free_all(&data));
	while (1)
	{
		instruct = get_next_line(0, &line);
		data.line = ft_strjoin_free_first(data.line, line);
		data.line = ft_strjoin_free_first(data.line, "\n");
		free(line);
		if (instruct == 0)
			break ;
	}
	if (exec_instruct(&data) < 0)
		return (1);
	if (!ft_strncmp(argv[1], "-v", 2))
		debug(&data);
	display_result(&data);
	return (1);
}
