/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		in_second_chunk(t_data *data)
{
	int push;

	pb(data);
	write(1, "pb\n", 3);
	rb(data);
	write(1, "rb\n", 3);
	push = 1;
	return (push);
}

void	push_if_in_chunk(t_data *data, int iter, int i)
{
	int j;
	int push;

	push = 0;
	j = 0;
	while (j < data->len_chunk + 1 && data->len_a > 0)
	{
		if ((data->a[0] == data->sorted_arr[iter]) && (push == 0))
		{
			pb(data);
			write(1, "pb\n", 3);
			push = 1;
		}
		else if (data->chunk_step[i] && (data->a[0] ==
			data->sorted_arr[iter + data->len_chunk]) && (push == 0))
			push = in_second_chunk(data);
		iter++;
		j++;
	}
	if (push == 0)
	{
		ra(data);
		write(1, "ra\n", 3);
	}
}

int		compare_with_chunk(t_data *data, int iter, int i)
{
	int j;
	int len;

	j = 0;
	len = data->len_a;
	while (j < len)
	{
		push_if_in_chunk(data, iter, i);
		j++;
	}
	return (1);
}

int		push_to_b(t_data *data)
{
	int i;
	int iter;

	iter = 0;
	i = 0;
	while (i < data->nb_chunk)
	{
		compare_with_chunk(data, iter, i);
		iter = iter + (data->len_chunk * 2) + 1;
		i++;
	}
	return (1);
}

int		push_algo(t_data *data)
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
