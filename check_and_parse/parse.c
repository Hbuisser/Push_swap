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

int	already_in_order(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	iter_check_digit(t_data *data, char **argv)
{
	int	i;

	i = data->i;
	while (argv[i])
	{
		if (check_digit(argv[i]))
			return (-1);
		i++;
	}
	return (1);
}

int	parse_stack(t_data *data, char **argv)
{
	int	i;
	int	j;

	data->len_a = data->init_len;
	data->a = (int *)malloc(sizeof(int) * data->init_len);
	if (!data->a)
		return (-1);
	j = data->i;
	i = 0;
	while (i < data->init_len)
	{
		data->a[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
	data->b = (int *)malloc(sizeof(int) * data->init_len);
	if (!data->b)
		return (-1);
	ft_bzero(data->b, data->init_len);
	if (iter_check_digit(data, argv) < 0)
		return (-1);
	return (1);
}

int	parse_stack_string(t_data *data, char **argv)
{
	int		i;
	int		len;
	char	**tab;

	data->string_bool = 1;
	tab = ft_split(argv[data->i], ' ');
	len = get_len(data, tab);
	data->a = (int *)malloc(sizeof(int) * len);
	if (!data->a)
		return (-1);
	i = 0;
	while (i < data->len_a)
	{
		data->a[i] = ft_atoi(tab[i]);
		i++;
	}
	data->b = (int *)malloc(sizeof(int) * len);
	if (!data->b)
		return (-1);
	if (check_digit_max_double(tab) < 0)
		return (-1);
	free_tab(tab);
	return (0);
}

int	parse(t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (argv[data->i][i])
	{
		if (argv[data->i][i] == ' ')
		{
			if (parse_stack_string(data, argv) < 0)
				return (-1);
			break ;
		}
		i++;
	}
	if (data->string_bool < 1)
		if (parse_stack(data, argv) < 0)
			return (-1);
	data->nb_chunk = get_nbr_chunck(data->len_a);
	data->sorted_arr = get_sorted_array(data->a, data->len_a);
	data->len_chunk = data->len_a / data->nb_chunk;
	data->chunk_step = (int *)malloc(sizeof(int) * data->nb_chunk);
	if (!data->chunk_step)
		return (-1);
	return (0);
}
