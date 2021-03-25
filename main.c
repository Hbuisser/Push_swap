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

int		check_digit(int argc, char **argv)
{
	int		i;
	int		j;
	i = 1;
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

void print_tab(int *tab, t_data *data)
{
    int i;

    i = data->init_len;
    printf("+++\n");
    while (i > 0)
    {
        printf("%i\n", tab[i]);
        i--;
    }
    printf("+++\n");
}

int parse_stack(char **argv, t_data *data)
{
    int i;

    i = 0;
    if (!(data->a = (int *)malloc(sizeof(int) * data->init_len)))
        return (0);
    while (i < data->init_len)
    {
        data->a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    //print_tab(data->a, data);
    if (!(data->b = (int *)malloc(sizeof(int) * data->init_len)))
        return (0);
    data->b[0] = 3;
    data->b[1] = 2;
    data->b[2] = 1;
    data->b[3] = 0;
    data->len_b = 4;
    return (1);
}

void init_struct(t_data *data, int argc)
{
    data->line = "";
    data->init_len = argc - 1;
    data->len_a = data->init_len;
    data->len_b = 0;
}

int main(int argc, char **argv)
{
    t_data data;
    int instruct;
    char *line;

    init_struct(&data, argc);
    parse_stack(argv, &data);
    //print_tab(data.tab, data);
    while (1)
    {
        instruct = get_next_line(0, &line);
        data.line = ft_strjoin(data.line, line);
        data.line = ft_strjoin(data.line, "\n");
        free(line);
        line = NULL;
        if (instruct == 0)
        {
            printf("___\ninstruct:\n%s", data.line);
            printf("OK\n___\n");
            break ;
        }
    }
    //sa(&data);
    //sb(&data);
    //ss(&data);
    // printf("a[0]: %i\n", data.a[0]);
    // printf("a[1]: %i\n", data.a[1]);
    // printf("a[2]: %i\n", data.a[2]);
    // printf("a[3]: %i\n", data.a[3]);
    // printf("a[4]: %i\n", data.a[4]);
    // printf("a[5]: %i\n", data.a[5]);
    // printf("a[6]: %i\n", data.a[6]);
    // printf("------\n");
    // printf("b[0]: %i\n", data.b[0]);
    // printf("b[1]: %i\n", data.b[1]);
    // printf("b[2]: %i\n", data.b[2]);
    // printf("b[3]: %i\n", data.b[3]);
    // printf("------------------\n");
    // pa(&data);
    // pa(&data);
    // pa(&data);
    // pb(&data);
    // pb(&data);
    // pb(&data);
    //print_tab(data.a);
    return (0);
}