/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
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

void sa(t_data *data)
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

void sb(t_data *data)
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

void ss(t_data *data)
{
    sa(data);
    sb(data);
}

/*
*** pa : push a - take the first element at the top of b and put it at the top of a. 
*** Do nothing if b is empty.
*/

int pa(t_data *data)
{
    int i;
    int j;
    int k;
    int *tmp;

    if (data->len_b == 0)
        return (1);
    data->len_a += 1;
    j = data->len_a;
    k = data->len_b;
    if (!(tmp= (int *)malloc(sizeof(int) * data->len_a - 1)))
        return (0);
    i = 0;
    while (i < data->len_a)
    {
        tmp[i] = data->a[i];
        i++;
    }
    i = 1;
    data->a[0] = data->b[0];
    while (i < j)
    {
        data->a[i] = tmp[i - 1];
        i++;
    }
    free(tmp);
    i = 0;
    while (i < k)
    {
        data->b[i] = data->b[i + 1];
        i++;
    }
    data->len_b -= 1;
    return (1);
}

/*
*** pb : push b - take the first element at the top of a and put it at the top of b. 
*** Do nothing if a is empty.
*/

int pb(t_data *data)
{
    int i;
    int j;
    int k;
    int *tmp;

    if (data->len_a == 0)
        return (1);
    data->len_b += 1;
    j = data->len_b;
    k = data->len_a;
    if (!(tmp= (int *)malloc(sizeof(int) * data->len_b - 1)))
        return (0);
    i = 0;
    while (i < data->len_b)
    {
        tmp[i] = data->b[i];
        i++;
    }
    i = 1;
    data->b[0] = data->a[0];
    while (i < j)
    {
        data->b[i] = tmp[i - 1];
        i++;
    }
    free(tmp);
    i = 0;
    while (i < k)
    {
        data->a[i] = data->a[i + 1];
        i++;
    }
    data->len_a -= 1;
    return (1);
}
