/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
*** pa : take the first element at the top of b and put it at the top of a.
*** Do nothing if b is empty.
*/

int	*get_tmp_a(t_data *data)
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * data->len_a);
	if (!tmp)
		return (0);
	i = 0;
	while (i < data->len_a)
	{
		tmp[i] = data->a[i];
		i++;
	}
	return (tmp);
}

int	pa(t_data *data)
{
	int	i;
	int	j;
	int	*tmp;

	if (data->len_b == 0)
		return (1);
	data->len_a += 1;
	j = data->len_a;
	tmp = get_tmp_a(data);
	data->a[0] = data->b[0];
	i = 1;
	while (i < j)
	{
		data->a[i] = tmp[i - 1];
		i++;
	}
	free(tmp);
	i = 0;
	data->len_b -= 1;
	while (i < data->len_b)
	{
		data->b[i] = data->b[i + 1];
		i++;
	}
	return (1);
}

/*
*** pb : take the first element at the top of a and put it at the top of b.
*** Do nothing if a is empty.
*/

int	*get_tmp_b(t_data *data)
{
	int	*tmp;
	int	i;

	tmp = (int *)malloc(sizeof(int) * data->len_b);
	if (!tmp)
		return (0);
	i = 0;
	while (i < data->len_b)
	{
		tmp[i] = data->b[i];
		i++;
	}
	return (tmp);
}

int	pb(t_data *data)
{
	int	i;
	int	j;
	int	*tmp;

	if (data->len_a == 0)
		return (1);
	data->len_b += 1;
	j = data->len_b;
	tmp = get_tmp_b(data);
	data->b[0] = data->a[0];
	i = 1;
	while (i < j)
	{
		data->b[i] = tmp[i - 1];
		i++;
	}
	free(tmp);
	i = 0;
	data->len_a -= 1;
	while (i < data->len_a)
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	return (1);
}
