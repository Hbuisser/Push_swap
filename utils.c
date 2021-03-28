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

void	printArray(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void	bring_above(t_data *data)
{
	int i;
	int index;

	i = 1;
	index = 0;
	while (i < data->len_a)
	{
		if (data->a[i] < data->a[index])
			index = i;
		i++;
	}
	while (index > 0)
	{
		ra(data);
		write(1, "ra\n", 3);
		index--;
	}
}

int free_all(t_data *data)
{
    if (data->a)
        free(data->a);
    if (data->b)
        free(data->b);
    if (data->chunk_step)
        free(data->chunk_step);
    if (data->sorted_arr)
        free(data->sorted_arr);
    return (1);
}

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
	int j;

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

int     check_digit_with_string(t_data *data)
{
    int i;
    int j;

	j = 0;
    i = data->i;
	while (i < data->len_a)
	{
		if (!ft_isdigit(data->a[i]))
			return (-1);
		i++;
	}
    return (0);
}

int     parse_stack(t_data *data, char **argv, int argc)
{
    int i;
    int j;

    data->len_a = data->init_len;
    if (!(data->a = (int *)malloc(sizeof(int) * data->init_len)))
        return (-1);
    j = data->i;
    i = 0;
    while (i < data->init_len)
    {
        data->a[i] = ft_atoi(argv[j]);
        i++;
        j++;
    }
    if (!(data->b = (int *)malloc(sizeof(int) * data->init_len)))
        return (-1);
    ft_bzero(data->b, data->init_len);
    if (check_digit(argc, argv, data->i))
    {
        write(1, "Error\n", 6);
        return (-1);
    }
    return (1);
}

void     free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int     parse_stack_string(t_data *data, char **argv, int i)
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
        return (-1);
    i = 0;
    while (i < data->len_a)
    {
        data->a[i] = ft_atoi(tab[i]);
        i++;
    }
    free_tab(tab);
    if (!(data->b = (int *)malloc(sizeof(int) * len)))
        return (-1);
    ft_bzero(data->b, len);
    printArray(data->a, data->len_a);
    // if (check_digit_with_string(data))
    // {
    //     write(1, "Error\n", 6);
    //     return (-1);
    // }
    return (0);
}

int	parse(t_data *data, char **argv, int argc)
{
	int i;

	i = 0;
	while (argv[data->i][i])
	{
		if (argv[data->i][i] == ' ')
			if (parse_stack_string(data, argv, data->i) < 0)
				return (-1);
		i++;
	}
	if (data->string_bool < 1)
		if (parse_stack(data, argv, argc) < 0)
			return (-1);
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

int check_double(t_data *data, char **argv)
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
            if (!(ft_strcmp(argv[j + data->i], argv[k + data->i])))
                return (1);
            k++;
        }
        j++;
    }
    return (0);
}

int	put_v_and_check(t_data *data, char **argv, int argc)
{
	if (!ft_strncmp(argv[1], "-v", 2))
		data->i = 2;
	if ((argc < 2 && data->string_bool == 0) || (argc == 2 && (!ft_strncmp(argv[1], "-v", 2) && data->string_bool == 0)))
		return (-1);
	if (check_double(data, argv) > 0)
		return (-1);
	// if (check_max(data, data->i, argv) > 0)
	// 	return (-1);
	return (0);
}

void init_struct(t_data *data, int argc, char **argv)
{
    data->i = 1;
    data->line = "";
    data->string_bool = 0;
    data->nb_chunk = 0;
    data->len_chunk = 0;
    data->init_len = argc - 1;
    if (!ft_strncmp(argv[1], "-v", 2))
        data->init_len -= 1;
    data->len_b = 0;
}
