/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void printArray(int *arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// int make_chunk_array(t_data *data, int *sorted_arr, int len)
// {
//     int *new_chunk;
//     int i;

//     if (!(new_chunk = (int *)malloc(sizeof(int) * data->len_chunk)))
//         return (0);
//     i = 0;
//     while (i < data->len_chunk)
//     {
//         new_chunk[i] = sorted_arr[len];
//         len++;
//         i++;
//     }
//     printArray(new_chunk, data->len_chunk);
//     return (0);
// }

// int     create_chunk(t_data *data, int *sorted_arr)
// {
//     int len;
//     int mod;
//     int i;
//     int j;

//     data->len_chunk = data->len_a / data->nb_chunk;
//     len = data->len_a / data->nb_chunk;
//     mod = data->len_a % data->nb_chunk;
//     //printf("mod%i\n", mod);
//     //printf("lena%i\n", data->len_a);
//     i = 0;
//     j = 0;
//     while (i < data->nb_chunk)
//     {
//         make_chunk_array(data, sorted_arr, j);
//         j = j + len;
//         i++;
//     }
//     return (1);
// }

int     get_nbr_chunck(int size)
{
    if (size < 99)
        return (4);
    else if (size < 495)
        return (6);
    else
        return (11);
}

void swap(int *xp, int *yp)
{
    int tmp = *xp;

    *xp = *yp;
    *yp = tmp;
}

int *get_sorted_array(int *arr, int n)
{
    int i;
    int j;
    int min;
    int *tmp_arr;
 
    if (!(tmp_arr = (int *)malloc(sizeof(int) * n)))
        return (0);
    i = 0;
    while (i < n)
    {
        tmp_arr[i] = arr[i];
        i++;
    }
    i = 0;
    while (i < n - 1)
    {
        min = i;
        j = i + 1;
        while (j < n)
        {    
            if (tmp_arr[j] < tmp_arr[min])
                min = j;
            j++;
        }    
        swap(&tmp_arr[min], &tmp_arr[i]);
        i++;
    }
    return (tmp_arr);
}

int main_algo(t_data *data)
{
    int i;
    int j;

    data->nb_chunk = get_nbr_chunck(data->len_a);
    data->sorted_arr = get_sorted_array(data->a, data->len_a);
    printArray(data->sorted_arr, data->len_a);
    data->len_chunk = data->len_a / data->nb_chunk;
    if (!(data->chunk_step = (int *)malloc(sizeof(int) * data->nb_chunk)))
        return (0);
    i = 0;
    j = data->len_chunk;
    while (i < data->nb_chunk - 1)
    {
        data->chunk_step[i] = j;
        j = j + data->len_chunk;
        i++;
    }
    data->chunk_step[i] = data->len_a;
    printArray(data->chunk_step, data->nb_chunk);
    first_chunk_push(data);
    //compare_unsorted_and_sorted(data);
    //create_chunk(data, sorted_arr);
    free(data->sorted_arr);
    return (0);
}

int main(int argc, char **argv)
{
    t_data data;
    int i;
    int j;

    if (argc < 2 || (argc == 2 && (!ft_strncmp(argv[1], "-v", 2))))
        return (0);
    i = 1;
    if (!ft_strncmp(argv[1], "-v", 2))
        i = 2;
    init_struct(&data, argc, argv);
    j = 0;
    while (argv[i][j])
    {
        if (argv[i][j] == ' ')
            if (ft_parse_string(&data, argv, i) < 0)
                return (0);
        j++;
    }
    j = 0;
    if (data.string_bool < 1)
    {
        parse_stack(argv, &data, i);
        if (check_digit(argc, argv, i))
        {
            write(1, "Error\n", 6);
            return (-1);
        }
    }
    if (already_in_order(&data) > 0)
        return (1);
    if (data.len_a < 6)
        small_bash(&data);
    else
        main_algo(&data);
    if (!ft_strncmp(argv[1], "-v", 2))
        debug(&data);
    return (1);
}