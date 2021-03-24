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
*** sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
*/

void sa(t_data *data)
{
    int swap_down;
    int swap_up;

    //if (data->a[0] && data->a[1])
    //{
        swap_down = data->a[0];
        swap_up = data->a[1];
        data->a[0] = swap_up;
        data->a[1] = swap_down;
    //}
    //else
      //  printf("A stack is empty\n");
    printf("a[0]: %i\n", data->a[0]);
    printf("a[1]: %i\n", data->a[1]);
    printf("a[2]: %i\n", data->a[2]);
}

/*
*** sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
*/

void sb(t_data *data)
{
    int swap_down;
    int swap_up;

    //if (data->b[0] && data->b[1])
    //{
        swap_down = data->b[0];
        swap_up = data->b[1];
        data->b[0] = swap_up;
        data->b[1] = swap_down;
    //}
    //else
      //  printf("B stack is empty\n");
    printf("b[0]: %i\n", data->b[0]);
    printf("b[1]: %i\n", data->b[1]);
    printf("b[2]: %i\n", data->b[2]);
}

/*
*** ss : sa and sb at the same time.
*/

void ss(t_data *data)
{
    int swap_down;
    int swap_up;

    //if (data->a[0] && data->a[1] && data->b[0] && data->b[1])
    //{
        swap_down = data->a[0];
        swap_up = data->a[1];
        data->a[0] = swap_up;
        data->a[1] = swap_down;
        swap_down = data->b[0];
        swap_up = data->b[1];
        data->b[0] = swap_up;
        data->b[1] = swap_down;
    //}
    //else
      //  printf("A or B stack is empty\n");
}

/*
*** pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
*/

void pa(t_data *data)
{
    int i;
    int first;

    i = 0;
    if (data->b[0])
    {
        while (data->b && data->b[i])
        {
            if (ft_isdigit(data->b[i]))
                i++;
        }
        first = data->b[i];
        //data->b[i] = NULL;
        i = 0;
        while (data->a && data->a[i])
        {
            if (ft_isdigit(data->a[i]))
                i++;
        }
        data->a[i] = first;
    }
    else
        printf("B stack is empty\n");
}

/*
*** pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
*/

void pb(t_data *data)
{
    int i;
    int first;

    i = 0;
    if (data->a[0])
    {
        while (data->a && data->a[i])
        {
            if (ft_isdigit(data->a[i]))
                i++;
        }
        first = data->a[i];
        //data->a[i] = NULL;
        i = 0;
        while (data->b && data->b[i])
        {
            if (ft_isdigit(data->b[i]))
                i++;
        }
        data->b[i] = first;
    }
    else
        printf("B stack is empty\n");
}
