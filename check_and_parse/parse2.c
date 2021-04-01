/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_int_min_max_tab(char **tab)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		if (ft_atoi_err_max(tab[i]) == -2)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	if (check_double_string(tab) > 0)
		return (-1);
	return (1);
}

int	check_digit_and_max(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (check_digit(tab[i]))
		{
			free_tab(tab);
			return (-1);
		}
		i++;
	}
	if (check_int_min_max_tab(tab) < 1)
	{
		free_tab(tab);
		return (-1);
	}
	return (1);
}

int	get_len(t_data *data, char **tab)
{
	int	i;
	int	j;

	data->len_a = 0;
	i = 0;
	j = 0;
	while (tab[i] != NULL)
		i++;
	data->len_a = i;
	return (i);
}
