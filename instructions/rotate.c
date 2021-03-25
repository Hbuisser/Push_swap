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
    // printf("a[0]: %i\n", data->a[0]);
    // printf("a[1]: %i\n", data->a[1]);
    // printf("a[2]: %i\n", data->a[2]);
    // printf("a[3]: %i\n", data->a[3]);
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
    // printf("b[0]: %i\n", data->b[0]);
    // printf("b[1]: %i\n", data->b[1]);
    // printf("b[2]: %i\n", data->b[2]);
    // printf("b[3]: %i\n", data->b[3]);
    return (1);
}

/*
*** rr : ra and rb at the same time.
*/

int rr(t_data *data)
{
    ra(data);
    rb(data);
    // printf("a[0]: %i\n", data->a[0]);
    // printf("a[1]: %i\n", data->a[1]);
    // printf("a[2]: %i\n", data->a[2]);
    // printf("b[0]: %i\n", data->b[0]);
    // printf("b[1]: %i\n", data->b[1]);
    // printf("b[2]: %i\n", data->b[2]);
    return (1);
}
