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

int hard_2_stack_b(t_data *data)
{
    int swap_down;
    int swap_up;

    if (data->len_b > 1)
    {
        if (data->b[0] > data->b[1])
        {
            swap_down = data->b[0];
            swap_up = data->b[1];
            data->b[0] = swap_up;
            data->b[1] = swap_down;
            write(1, "sa\n", 3);
        }
    }
    return (1);
}

int hard_2(t_data *data)
{
    if (data->a[0] > data->a[1])
    {
        sa(data);
        write(1, "sa\n", 3);
    }
    return (1);
}

int hard_3(t_data *data)
{
    if (data->a[0] < data->a[1] && data->a[1] < data->a[2])
        return (1);
    else if (data->a[0] > data->a[1] && data->a[1] < data->a[2] &&
            data->a[2] > data->a[0])
    {
        sa(data);
        write(1, "sa\n", 3);
        return (1);
    }
    else if (data->a[0] > data->a[1] && data->a[1] > data->a[2] &&
            data->a[2] < data->a[0])
    {
        sa(data);
        rra(data);
        write(1, "sa\n", 3);
        write(1, "rra\n", 4);
        return (1);
    }
    else if (data->a[0] > data->a[1] && data->a[1] < data->a[2] &&
            data->a[2] < data->a[0])
    {
        ra(data);
        write(1, "ra\n", 3);
        return (1);
    }
    else if (data->a[0] < data->a[1] && data->a[1] > data->a[2] &&
            data->a[2] > data->a[0])
    {
        sa(data);
        ra(data);
        write(1, "sa\n", 3);
        write(1, "ra\n", 3);
        return (1);
    }
    else if (data->a[0] < data->a[1] && data->a[1] > data->a[2] &&
            data->a[2] < data->a[0])
    {
        rra(data);
        write(1, "rra\n", 4);
        return (1);
    }
    return (1);
}

int hard_4(t_data *data)
{
    pb(data);
    write(1, "pb\n", 3);
    hard_3(data);
    pa(data);
    write(1, "pa\n", 3);
    if (data->a[0] > data->a[1])
    {
        sa(data);
        write(1, "sa\n", 3);
        pb(data);
        write(1, "pb\n", 3);
        hard_3(data);
        pa(data);
        write(1, "pa\n", 3);
        return (1);
    }
    return (1);
}

int hard_5(t_data *data)
{
    pb(data);
    pb(data);
    write(1, "pb\n", 3);
    write(1, "pb\n", 3);
    hard_3(data);
    pa(data);
    write(1, "pa\n", 3);
    if (data->a[0] > data->a[1])
    {
        sa(data);
        write(1, "sa\n", 3);
        pb(data);
        write(1, "pb\n", 3);
        hard_3(data);
        pa(data);
        write(1, "pa\n", 3);
    }
    pa(data);
    write(1, "pa\n", 3);
    if (data->a[0] > data->a[1])
        hard_4(data);
    return (1);
}

int already_in_order(t_data *data)
{
    int i;

    i = 0;
    while (i < data->len_a - 1)
    {
        if (data->a[i] > data->a[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int small_bash(t_data * data)
{
    int tmp;

    tmp = 0;
    if (data->len_a == 2)
        hard_2(data);
    else if (data->len_a == 3)
        hard_3(data);
    else if (data->len_a == 4)
        hard_4(data);
    else if (data->len_a == 5)
        hard_5(data);
    return (0);
}