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

int compare_unsorted_and_sorted(t_data *data)
{
    int i;
    int j;
    int k;
    int push;

    i = 0;
    j = 0;
    k = 0;
    push = 0;
    //nb_chunk = 4
    //chunk_step = tableau int avec indice

    // itere dans les chunks
    while (i < data->nb_chunk)
    {
        // dans le premier chunk, voir si le premier de la unsorted est dans le chunk
    // si oui, pa
        while (j < data->chunk_step[i])
        {
            if (data->a[0] == data->sorted_arr[k])
            {
                pb(data);
                write(1, "pb\n", 3);
                push = 1;
                j++;
                break ;
            }
            j++;
        }
    // si non ra
    // avancer de 1 dans la unsorted

        i++;
    }



    // while (i < data->nb_chunk)
    // {
    //     j = 0;
    //     while (j < data->chunk_step[i])
    //     {
    //         if (data->a[0] == data->sorted_arr[k])
    //         {
    //             pb(data);
    //             write(1, "pb\n", 3);
    //             push = 1;
    //             j++;
    //             break ;
    //         }
    //         k++;
    //         j++;
    //     }
    //     if (push == 0)
    //     {
    //         ra(data);
    //         write(1, "ra\n", 3);
    //     }



    //     i++;
    // }
    return (1);
}
