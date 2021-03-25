/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		check_digit(int argc, char **argv, int i)
{
	int		j;

	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int display_result(t_data *data)
{
    int i;

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

int debug(t_data *data)
{
    int i;

    i = 0;
    while (i < data->len_a)
    {
        printf("a[%i]: %i\n", i, data->a[i]);
        i++;
    }
    i = 0;
    while (i < data->len_b)
    {
        printf("b[%i]: %i\n", i, data->b[i]);
        i++;
    }
    return (0);
}

int exec_instruct(t_data *data)
{
    int i;
    char **instruct;

    instruct = ft_split(data->line, '\n');
    i = 0;
    while (instruct && instruct[i])
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
        i++;
    }
    return (1);
}

int parse_stack(char **argv, t_data *data, int j)
{
    int i;

    i = 0;
    if (!(data->a = (int *)malloc(sizeof(int) * data->init_len)))
        return (0);
    while (i < data->init_len)
    {
        data->a[i] = ft_atoi(argv[j]);
        i++;
        j++;
    }
    if (!(data->b = (int *)malloc(sizeof(int) * data->init_len)))
        return (0);
    return (1);
}

void init_struct(t_data *data, int argc, char **argv)
{
    data->line = "";
    data->len_a = data->init_len;
    data->len_b = 0;
    data->init_len = argc - 1;
    if (!ft_strncmp(argv[1], "-v", 2))
        data->init_len -= 1;
}

int main(int argc, char **argv)
{
    t_data data;
    int instruct;
    char *line;
    int i;

    if (argc < 2 || (argc == 2 && (!ft_strncmp(argv[1], "-v", 2))))
        return (0);
    i = 1;
    if (!ft_strncmp(argv[1], "-v", 2))
        i = 2;
    init_struct(&data, argc, argv);
    if (check_digit(argc, argv, i) < 0)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    parse_stack(argv, &data, i);
    while (1)
    {
        instruct = get_next_line(0, &line);
        data.line = ft_strjoin(data.line, line);
        data.line = ft_strjoin(data.line, "\n");
        free(line);
        line = NULL;
        if (instruct == 0)
            break ;
    }
    exec_instruct(&data);
    if (!ft_strncmp(argv[1], "-v", 2))
        debug(&data);
    display_result(&data);
    return (0);
}