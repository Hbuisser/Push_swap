/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_int_min_max(t_data *data, char *str)
{
	if (ft_atoi_err_max(str) == 10000)
	{
		free(data->line);
		return (-1);
	}
	return (1);
}

int	check_max(t_data *data, int nb, char **argv)
{
	int	i;

	i = 0;
	if (data->string_bool == 0)
	{
		while (i < data->init_len)
		{
			if (check_int_min_max(data, argv[nb + i]) < 1)
				return (-1);
			i++;
		}
	}
	return (1);
}

int	check_double(t_data *data, char **argv)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < data->init_len)
	{
		k = j + 1;
		while (k < data->init_len)
		{
			if (!(ft_strcmp(argv[j + data->i], argv[k + data->i])))
			{
				free(data->line);
				write(2, "Error\n", 6);
				return (1);
			}
			k++;
		}
		j++;
	}
	return (0);
}

int	check(t_data *data, char **argv, int argc)
{
	if (argc == 1)
	{
		free(data->line);
		return (-1);
	}
	if (!ft_strncmp(argv[1], "-v", 2))
		data->i = 2;
	if ((argc < 2 && data->string_bool == 0) || (argc == 2
			&& (!ft_strncmp(argv[1], "-v", 2) && data->string_bool == 0)))
		return (-1);
	if (check_double(data, argv) > 0)
		return (-1);
	if (check_max(data, data->i, argv) < 0)
		return (-1);
	return (0);
}
