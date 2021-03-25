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
        if (!ft_strncmp(instruct[i], "sa", 2))
            sa(data);
        else if (!ft_strncmp(instruct[i], "sb", 2))
            sb(data);
        else if (!ft_strncmp(instruct[i], "ss", 2))
            ss(data);
        else if (!ft_strncmp(instruct[i], "pa", 2))
            pa(data);
        else if (!ft_strncmp(instruct[i], "pb", 2))
            pb(data);
        else if (!ft_strncmp(instruct[i], "ra", 2))
            ra(data);
        else if (!ft_strncmp(instruct[i], "rb", 2))
            rb(data);
        else if (!ft_strncmp(instruct[i], "rr", 2))
            rr(data);
        else if (!ft_strncmp(instruct[i], "rra", 3))
            rra(data);
        else if (!ft_strncmp(instruct[i], "rrb", 3))
            rrb(data);
        else if (!ft_strncmp(instruct[i], "rrr", 3))
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

void init_struct(t_data *data)
{
    data->line = "";
    data->len_a = data->init_len;
    data->len_b = 0;
}

int main(int argc, char **argv)
{
    t_data data;
    int instruct;
    char *line;
    int i;

    i = 1;
    data.init_len = argc - 1;
    if (!ft_strncmp(argv[1], "-v", 2))
    {
        i = 2;
        data.init_len -= 1;
    }
    init_struct(&data);
    if (check_digit(argc, argv, i) < 0)
        return (0); 
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
    return (0);
}