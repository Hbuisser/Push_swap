/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		already_in_order(t_data *data)
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

int		parse_stack(t_data *data, char **argv, int argc)
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
		return (-1);
	return (1);
}

int		get_len(t_data *data, char **argv)
{
	int len;
	int j;

	j = 0;
	len = 0;
	while (argv[data->i][j])
	{
		if (argv[data->i][j] == ' ')
			len++;
		j++;
	}
	len++;
	data->len_a = len;
	return (len);
}

int		parse_stack_string(t_data *data, char **argv)
{
	int		i;
	int		len;
	char	**tab;

	data->string_bool = 1;
	tab = ft_split(argv[data->i], ' ');
	len = get_len(data, argv);
	if (!(data->a = (int *)malloc(sizeof(int) * len)))
		return (-1);
	i = 0;
	while (i < data->len_a)
	{
		data->a[i] = ft_atoi(tab[i]);
		i++;
	}
	if (!(data->b = (int *)malloc(sizeof(int) * len)))
		return (-1);
	ft_bzero(data->b, len);
	if (check_digit(len, tab, 0))
		return (-1);
	if (check_int_min_max_tab(tab) < 1)
		return (-1);
	free_tab(tab);
	return (0);
}

int		parse(t_data *data, char **argv, int argc)
{
	int i;

	i = 0;
	while (argv[data->i][i])
	{
		if (argv[data->i][i] == ' ')
			if (parse_stack_string(data, argv) < 0)
				return (-1);
		i++;
	}
	if (data->string_bool < 1)
		if (parse_stack(data, argv, argc) < 0)
			return (-1);
	return (0);
}
