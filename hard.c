/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	hard_2(t_data *data)
{
	if (data->a[0] > data->a[1])
	{
		sa(data);
		write(1, "sa\n", 3);
	}
	return (1);
}

int	hard_3_bis(t_data *data)
{
	if (data->a[0] > data->a[1] && data->a[1] < data->a[2] &&
		data->a[2] < data->a[0])
	{
		ra(data);
		write(1, "ra\n", 3);
		return (1);
	}
	else if (data->a[0] < data->a[1] && data->a[1] > data->a[2] &&
		data->a[2] > data->a[0])
	{
		sa(data);
		ra(data);
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
		return (1);
	}
	else if (data->a[0] < data->a[1] && data->a[1] > data->a[2] &&
		data->a[2] < data->a[0])
	{
		rra(data);
		write(1, "rra\n", 4);
		return (1);
	}
	return (1);
}

int	hard_3(t_data *data)
{
	if (data->a[0] < data->a[1] && data->a[1] < data->a[2])
		return (1);
	else if (data->a[0] > data->a[1] && data->a[1] < data->a[2] &&
		data->a[2] > data->a[0])
	{
		sa(data);
		write(1, "sa\n", 3);
		return (1);
	}
	else if (data->a[0] > data->a[1] && data->a[1] > data->a[2] &&
		data->a[2] < data->a[0])
	{
		sa(data);
		rra(data);
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
		return (1);
	}
	hard_3_bis(data);
	return (1);
}

//////////////// no good
int	hard_4(t_data *data)
{
	pb(data);
	write(1, "pb\n", 3);
	hard_3(data);
	pa(data);
	write(1, "pa\n", 3);
	if (data->a[0] > data->a[1])
	{
		sa(data);
		write(1, "sa\n", 3);
		pb(data);
		write(1, "pb\n", 3);
		hard_3(data);
		pa(data);
		write(1, "pa\n", 3);
		return (1);
	}
	return (1);
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

int	hard_5(t_data *data)
{
	bring_above(data);
	pb(data);
	write(1, "pb\n", 3);
	bring_above(data);
	pb(data);
	write(1, "pb\n", 3);
	hard_3(data);
	pa(data);
	write(1, "pa\n", 3);
	if (data->a[0] > data->a[1])
	{
		sa(data);
		write(1, "sa\n", 3);
		pb(data);
		write(1, "pb\n", 3);
		hard_3(data);
		pa(data);
		write(1, "pa\n", 3);
	}
	pa(data);
	write(1, "pa\n", 3);
	if (data->a[0] > data->a[1])
		hard_4(data);
	return (1);
}
