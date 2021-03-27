/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
*** sa : swap a - swap the first 2 elements at the top of stack a.
*** Do nothing if there is only one or no elements).
*/

void	sa(t_data *data)
{
	int swap_down;
	int swap_up;

	if (data->len_a > 1)
	{
		swap_down = data->a[0];
		swap_up = data->a[1];
		data->a[0] = swap_up;
		data->a[1] = swap_down;
	}
}

/*
*** sb : swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements).
*/

void	sb(t_data *data)
{
	int swap_down;
	int swap_up;

	if (data->len_b > 1)
	{
		swap_down = data->b[0];
		swap_up = data->b[1];
		data->b[0] = swap_up;
		data->b[1] = swap_down;
	}
}

/*
*** ss : sa and sb at the same time.
*/

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
