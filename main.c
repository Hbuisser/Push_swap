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

void print_tab(int *tab)
{
    int i;

    i = 0;
    printf("+++\n");
    while (tab && tab[i + 1])
    {
        printf("%d\n", tab[i]);
        i++;
    }
    printf("+++\n");
}

int parse_stack(int argc, char **argv, t_data *data)
{
    int i;
    int len;

    i = 0;
    len = argc - 1;
    if (!(data->a = malloc(sizeof(int) * len)))
        return (0);
    while (i < len)
    {
        data->a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    if (!(data->b = malloc(sizeof(int) * len)))
        return (0);
    data->b[0] = 0;
    data->b[1] = 1;
    data->b[2] = 2;
    data->b[3] = 3;
    return (1);
}

int main(int argc, char **argv)
{
    t_data data;
    int instruct;
    char *line;

    data.line = "";
    parse_stack(argc, argv, &data);
    //print_tab(data.tab);
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
    sa(&data);
    sb(&data);
    //print_tab(data.a);
    return (0);
}