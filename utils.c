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

int already_in_order(t_data *data)
{
    int i;

    i = 0;
    while (i < data->len_a - 1)
    {
        if (data->a[i] > data->a[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int		check_int_min_max(char *str)
{
	if (((str[0] == '+' || str[0] == '-') && ft_strlen(str + 1) < 10)
		|| ft_strlen(str) < 10)
		return (1);
	if (((str[0] == '+' || str[0] == '-') && ft_strlen(str + 1) > 10)
		|| ft_strlen(str) > 11)
		return (0);
	if ((str[0] == '+' && ft_strncmp("2147483647", str + 1, 12) < 0)
		|| (str[0] == '-' && ft_strncmp("2147483648", str + 1, 12) < 0)
		|| (ft_isdigit(str[0]) && ft_strncmp("2147483647", str, 12) < 0))
		return (0);
	return (1);
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

int     ft_parse_string(t_data *data, char **argv, int i)
{
    int j;
    int len;
    char    **tab;

    data->string_bool = 1;
    tab = ft_split(argv[i], ' ');
    j = 0;
    len = 0;
    while (argv[i][j])
    {
        if (argv[i][j] == ' ')
            len++;
        j++;
    }
    len++;
    data->len_a = len;
    if (!(data->a = (int *)malloc(sizeof(int) * len)))
        return (0);
    i = 0;
    while (i < data->len_a)
    {
        data->a[i] = ft_atoi(tab[i]);
        i++;
    }
    i = 0;
    if (check_digit(len, tab, i))
    {
        write(1, "Error\n", 6);
        return (-1);
    }
    return (0);
}

int check_max(t_data *data, int nb, char **argv)
{
    int i;

    i = 0;
    while (i < data->init_len)
    {
        if (check_int_min_max(argv[nb + i]) < 1)
            return (1);
        i++;
    }
    return (0);
}

int check_double(t_data *data, int i, char **argv)
{
    int j;
    int k;

    j = 0;
    k = 0;
    while (j < data->init_len)
    {
        k = j + 1;
        while (k < data->init_len)
        {
            if (!(ft_strcmp(argv[j + i], argv[k + i])))
                return (1);
            k++;
        }
        j++;
    }
    return (0);
}

void init_struct(t_data *data, int argc, char **argv)
{
    data->line = "";
    data->string_bool = 0;
    data->nb_chunk = 0;
    data->len_chunk = 0;
    data->init_len = argc - 1;
    if (!ft_strncmp(argv[1], "-v", 2))
        data->init_len -= 1;
    data->len_b = 0;
}
