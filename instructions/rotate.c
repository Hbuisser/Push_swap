/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
*** ra : rotate a - shift up all elements of stack a by 1. 
*** The first element becomes the last one.
*/

int ra(t_data *data)
{
    int i;
    int *tmp;

    if (!(tmp= (int *)malloc(sizeof(int) * data->len_a - 1)))
        return (0);
    i = 0;
    while (i < data->len_a)
    {
        tmp[i] = data->a[i];
        i++;
    }
    i = data->len_a - 1;
    data->a[i] = tmp[0];
    while (i > 0)
    {
        data->a[i - 1] = tmp[i];
        i--;
    }
    free(tmp);
    return (1);
}

/*
*** rb : rotate b - shift up all elements of stack b by 1. 
*** The first element becomes the last one.
*/

int rb(t_data *data)
{
    int i;
    int *tmp;

    if (!(tmp= (int *)malloc(sizeof(int) * data->len_b - 1)))
        return (0);
    i = 0;
    while (i < data->len_b)
    {
        tmp[i] = data->b[i];
        i++;
    }
    i = data->len_b - 1;
    data->b[i] = tmp[0];
    while (i > 0)
    {
        data->b[i - 1] = tmp[i];
        i--;
    }
    free(tmp);
    return (1);
}

/*
*** rr : ra and rb at the same time.
*/

int rr(t_data *data)
{
    ra(data);
    rb(data);
    return (1);
}
