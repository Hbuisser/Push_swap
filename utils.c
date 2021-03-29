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

void	printArray(int *arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
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

int free_all(t_data *data)
{
    if (data->a)
        free(data->a);
    if (data->b)
        free(data->b);
    if (data->chunk_step)
        free(data->chunk_step);
    if (data->sorted_arr)
        free(data->sorted_arr);
    return (1);
}

void debug(t_data *data)
{
    int i;

    i = 0;
    while (i < data->len_a)
    {
        printf("a[%i]: %i\n", i, data->a[i]);
        i++;
    }
    i = 0;
    while (i < data->len_b)
    {
        printf("b[%i]: %i\n", i, data->b[i]);
        i++;
    }
}

int		check_digit(int argc, char **argv, int i)
{
	int j;

	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void     free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void init_struct(t_data *data, int argc, char **argv)
{
    data->i = 1;
    data->line = "";
    data->nb_chunk = 0;
    data->len_chunk = 0;
    data->init_len = argc - 1;
    if (argv[1] && !ft_strncmp(argv[1], "-v", 2))
        data->init_len -= 1;
    data->len_b = 0;
    data->string_bool = 0;
}

void	swap(int *xp, int *yp)
{
	int tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

int		*get_sorted_array(int *arr, int n)
{
	int i;
	int j;
	int min;
	int *tmp_arr;

	if (!(tmp_arr = (int *)malloc(sizeof(int) * n)))
		return (0);
	i = -1;
	while (++i < n)
		tmp_arr[i] = arr[i];
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
