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

int	check_double_string(char **tab)
{
	size_t	len;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	len = 0;
	while (tab[len] != NULL)
		len++;
	while (j < len)
	{
		k = j + 1;
		while (k < len)
		{
			if (!(ft_strncmp(tab[j], tab[k], len)))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			k++;
		}
		j++;
	}
	return (0);
}

int	check_int_min_max_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atoi_err_max(tab[i]) == 10000)
			return (-1);
		i++;
	}
	return (1);
}

int	check_digit_max_double(char **tab)
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
	if (check_double_string(tab) > 0)
	{
		free_tab(tab);
		return (-1);
	}
	return (1);
}
