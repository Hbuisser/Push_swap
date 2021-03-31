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

void	bring_above(t_data *data)
{
	int	i;
	int	index;

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

int	check_digit(int argc, char **argv, int i)
{
	int	j;

	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	swap(int *xp, int *yp)
{
	int	tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

int	*get_tmp_arr(int *arr, int n)
{
	int	*tmp_arr;
	int	i;

	tmp_arr = (int *)malloc(sizeof(int) * n);
	if (!tmp_arr)
		return (0);
	i = -1;
	while (++i < n)
		tmp_arr[i] = arr[i];
	return (tmp_arr);
}

int	*get_sorted_array(int *arr, int n)
{
	int	i;
	int	j;
	int	min;
	int	*tmp_arr;

	tmp_arr = get_tmp_arr(arr, n);
	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (tmp_arr[j] < tmp_arr[min])
				min = j;
			j++;
		}
		swap(&tmp_arr[min], &tmp_arr[i]);
		i++;
	}
	return (tmp_arr);
}
