/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int hard_3(t_data *data)
{
    if (data->a[0] < data->a[1] && data->a[1] < data->a[2])
        return (1);
    else if (data->a[0] > data->a[1] && data->a[1] < data->a[2] &&
            data->a[2] > data->a[0])
    {
        write(1, "sa\n", 3);
        return (1);
    }
    else if (data->a[0] > data->a[1] && data->a[1] > data->a[2] &&
            data->a[2] < data->a[0])
    {
        write(1, "sa\n", 3);
        write(1, "rra\n", 4);
        return (1);
    }
    else if (data->a[0] > data->a[1] && data->a[1] < data->a[2] &&
            data->a[2] < data->a[0])
    {
        write(1, "ra\n", 3);
        return (1);
    }
    else if (data->a[0] < data->a[1] && data->a[1] > data->a[2] &&
            data->a[2] > data->a[0])
    {
        write(1, "sa\n", 3);
        write(1, "ra\n", 3);
        return (1);
    }
    else if (data->a[0] < data->a[1] && data->a[1] > data->a[2] &&
            data->a[2] < data->a[0])
    {
        write(1, "rra\n", 4);
        return (1);
    }
    return (1);
}

int small_bash(t_data * data)
{
    int tmp;

    tmp = 0;
    if (data->len_a == 2)
    {
        if (data->a[0] > data->a[1])
            write(1, "sa\n", 3);
        return (1);
    }
    else if (data->len_a == 3)
        hard_3(data);
    return (0);
}