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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	free_all(t_data *data)
{
	if (data->line)
		free(data->line);
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
	int	i;

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

int	get_nbr_chunck(int size)
{
	if (size < 10)
		return (2);
	if (size < 99)
		return (4);
	else if (size < 495)
		return (8);
	else
		return (18);
}
