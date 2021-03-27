/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int compare_and_push(t_data *data, int iter)
{
    int i;
    int j;
    int k;
    int l;
    int push;
    int len;

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    push = 0;


    k = k + iter;
    l = k;
    len = data->len_a;
    printf("lena%i\n", data->len_a);
    while (i < len)
    {
        push = 0;
        j = 0;
        l = k;
        while (j < data->len_chunk + 1 && data->len_a > 0)
        {
            printf("a[0]:%i\n", data->a[0]);
            printf("sorted[l]:%i\n", data->sorted_arr[l]);
            if ((data->a[0] == data->sorted_arr[l]) && (push == 0))
            {
                printf("push\n");
                pb(data);
                write(1, "pb\n", 3);
                push = 1;
            }
            l++;
            j++;
        }
        if (push == 0)
        {
            ra(data);
            write(1, "ra\n", 3);
        }
        i++;
        printf("i: %i\n", i);
        printf("-------------\n");
    }

    return (1);
}


int compare_unsorted_and_sorted(t_data *data)
{
    int i;
    int iter;

    iter = 0;
    i = 0;
    while (i < data->nb_chunk)
    {
        compare_and_push(data, iter);
        iter = iter + data->len_chunk + 1;
        i++;
    }
    return (1);
}

