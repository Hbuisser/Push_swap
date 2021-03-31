/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:05:12 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/12/11 16:31:13 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_long(int signe)
{
	if (signe == -1)
		return (0);
	else
		return (-1);
}

static int	ft_return(unsigned long long result, int signe)
{
	if (signe == -1 && (result - 1) == 9223372036854775807)
		return (result * signe);
	if (result > 9223372036854775807)
		return (ft_long(signe));
	return (result * signe);
}

long long	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	result;

	result = 0;
	signe = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (ft_return(result, signe));
}
