/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int		check_double_string(t_data *data, char **tab, char **argv)
{
	size_t j;
	size_t k;

	j = 0;
	k = 0;
	while (j < ft_strlen(argv[data->i]))
	{
		k = j + 1;
		while (tab[k] != NULL && k < ft_strlen(argv[data->i]))
		{
	write(1, "couc\n", 5);
	printf("tabj%s\n", tab[j]);
	printf("tabj%s\n", tab[k]);
			if ((!(ft_strcmp(tab[j], tab[k]))))
			{
				write(1, "Error\n", 6);
				return (1);
			}
			k++;
		}
		j++;
	}
	return (0);
}

void	free_tab(char **tab)
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

int		free_all(t_data *data)
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

void	debug(t_data *data)
{
	int i;

	i = 0;
	while (i < data->len_a)
	{
		ft_putnbr_fd(data->a[i], 1);
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < data->len_b)
	{
		ft_putnbr_fd(data->b[i], 1);
		write(1, "\n", 1);
		i++;
	}
}
