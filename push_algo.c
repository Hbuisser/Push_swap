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

void	push_if_in_chunk(t_data *data, int k)
{
	int j;
	int l;
	int push;

	push = 0;
	j = 0;
	l = k;
	while (j < data->len_chunk + 1 && data->len_a > 0)
	{
		if ((data->a[0] == data->sorted_arr[l]) && (push == 0))
		{
			pb(data);
			write(1, "pb\n", 3);
			push = 1;
		}
		l++;
		j++;
	}
	if (push == 0)
	{
		ra(data);
		write(1, "ra\n", 3);
	}
}

int		compare_with_chunk(t_data *data, int iter)
{
	int i;
	int len;
	int k;

	i = 0;
	len = data->len_a;
	k = 0;
	k = k + iter;
	while (i < len)
	{
		push_if_in_chunk(data, k);
		i++;
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
		compare_with_chunk(data, iter);
		iter = iter + data->len_chunk + 1;
		i++;
	}
	return (1);
}
