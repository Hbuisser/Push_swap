/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int     get_nbr_chunck(int size)
{
    if (size < 99)
        return (4);
    else if (size < 495)
        return (6);
    else
        return (11);
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
        data.nb_chunk = get_nbr_chunck(data.len_a);
    if (!ft_strncmp(argv[1], "-v", 2))
        debug(&data);
    return (1);
}