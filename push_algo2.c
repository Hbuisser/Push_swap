/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		put_at_first_place(t_data *data, int half, int index)
{
	if (half == 1)
	{
		while (index > 0)
		{
			rb(data);
			write(1, "rb\n", 3);
			index--;
		}
	}
	else
	{
		while (index < data->len_b)
		{
			rrb(data);
			write(1, "rrb\n", 4);
			index++;
		}
	}
	return (1);
}

int		get_half(t_data *data, int index)
{
	int half;
	int middle;

	middle = data->len_b / 2;
	if (index < middle)
		half = 1;
	else
		half = -1;
	return (half);
}

int		find_max(t_data *data)
{
	int i;
	int len;
	int index;

	index = 0;
	len = data->len_b;
	i = 1;
	while (i < len)
	{
		if (data->b[i] > data->b[index])
			index = i;
		i++;
	}
	return (index);
}

int		push_to_a(t_data *data)
{
	int i;
	int index;
	int half;

	i = 0;
	while (i < data->len_b)
	{
		index = find_max(data);
		half = get_half(data, index);
		put_at_first_place(data, half, index);
		pa(data);
		write(1, "pa\n", 3);
	}
	return (1);
}
