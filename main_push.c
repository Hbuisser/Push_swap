/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		get_nbr_chunck(int size)
{
	if (size < 99)
		return (4);
	else if (size < 495)
		return (6);
	else
		return (11);
}

int		main_algo(t_data *data)
{
	int i;
	int j;

	data->nb_chunk = get_nbr_chunck(data->len_a);
	data->sorted_arr = get_sorted_array(data->a, data->len_a);
	data->len_chunk = data->len_a / data->nb_chunk;
	if (!(data->chunk_step = (int *)malloc(sizeof(int) * data->nb_chunk)))
		return (-1);
	i = 0;
	j = data->len_chunk;
	while (i < data->nb_chunk - 1)
	{
		data->chunk_step[i] = j;
		j = j + data->len_chunk;
		i++;
	}
	data->chunk_step[i] = data->len_a - 1;
	push_to_b(data);
	push_to_a(data);
	return (1);
}

int		small_bash(t_data *data)
{
	int tmp;

	tmp = 0;
	if (data->len_a == 2)
		hard_2(data);
	else if (data->len_a == 3)
		hard_3(data);
	else if (data->len_a == 4)
		hard_4(data);
	else if (data->len_a == 5)
		hard_5(data);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data data;

	init_struct(&data, argc, argv);
	if (check(&data, argv, argc) < 0)
		return (0);
	if (parse(&data, argv, argc) < 0)
		return (free_all(&data));
	if (already_in_order(&data) > 0)
		return (free_all(&data));
	if (data.len_a < 6)
		small_bash(&data);
	else
	{
		if (main_algo(&data) < 0)
			return (0);
	}
	if (!ft_strncmp(argv[1], "-v", 2))
		debug(&data);
	free_all(&data);
	return (1);
}
