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
    while (tab[i + 1])
    {
        printf("%i\n", tab[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_data data;
    int i;
    int *tab;
    int len;
    int instruct;
    char *line;

    i = 0;
    len = argc - 1;
    tab = malloc(sizeof(int) * len);
    data.line = "";
    while (i < len)
    {
        tab[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    print_tab(tab);
    while (1)
    {
        instruct = get_next_line(0, &line);
        data.line = ft_strjoin(data.line, line);
        free(line);
        line = NULL;
        if (instruct == 0)
        {
            printf("instruct: %s|\n", data.line);
            write(1, "OK\n", 3);
            return (0);
        }
    }
    return (0);
}