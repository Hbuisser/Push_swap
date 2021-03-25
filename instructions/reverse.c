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
*** rra : reverse rotate a - shift down all elements of stack a by 1. 
*** The last element becomes the first one.
*/

int rra(t_data *data)
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
    data->a[0] = tmp[data->len_a - 1];
    i = 1;
    while (i < data->len_a)
    {
        data->a[i] = tmp[i - 1];
        i++;
    }
    free(tmp);
    // printf("a[0]: %i\n", data->a[0]);
    // printf("a[1]: %i\n", data->a[1]);
    // printf("a[2]: %i\n", data->a[2]);
    // printf("a[3]: %i\n", data->a[3]);
    return (1);
}

/*
*** rrb : reverse rotate b - shift down all elements of stack a by 1. 
*** The last element becomes the first one.
*/

int rrb(t_data *data)
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
    data->b[0] = tmp[data->len_b - 1];
    i = 1;
    while (i < data->len_b)
    {
        data->b[i] = tmp[i - 1];
        i++;
    }
    free(tmp);
    // printf("b[0]: %i\n", data->b[0]);
    // printf("b[1]: %i\n", data->b[1]);
    // printf("b[2]: %i\n", data->b[2]);
    // printf("b[3]: %i\n", data->b[3]);
    return (1);
}

/*
*** rrr : rra and rrb at the same time.
*/

int rrr(t_data *data)
{
    rra(data);
    rrb(data);
    // printf("a[0]: %i\n", data->a[0]);
    // printf("a[1]: %i\n", data->a[1]);
    // printf("a[2]: %i\n", data->a[2]);
    // printf("b[0]: %i\n", data->b[0]);
    // printf("b[1]: %i\n", data->b[1]);
    // printf("b[2]: %i\n", data->b[2]);
    return (1);
}
