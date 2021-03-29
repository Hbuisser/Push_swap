/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:19:49 by hbuisser          #+#    #+#             */
/*   Updated: 2019/10/28 10:02:31 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_manage_longmin(unsigned long result, int count)
{
	int value;

	if (count % 2 != 0)
		value = -1;
	else
		value = 1;
	if (result > 2147483648)
		return (-2);
	if (value == -1 && result > 2147483648)
		return (-2);
	else if (value == 1 && result > 2147483647)
		return (-2);
	return (result * value);
}

int	ft_atoi_err_max(const char *str)
{
	int				i;
	int				count;
	unsigned long	result;

	i = 0;
	count = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (ft_manage_longmin(result, count));
}
