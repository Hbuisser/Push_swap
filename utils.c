/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

int parse_stack(char **argv, t_data *data, int j)
{
    int i;

    i = 0;
    data->len_a = data->init_len;
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
    data->string_bool = 0;
    data->nb_chunk = 0;
    data->init_len = argc - 1;
    if (!ft_strncmp(argv[1], "-v", 2))
        data->init_len -= 1;
    //data->len_a = data->init_len;
    data->len_b = 0;
}
