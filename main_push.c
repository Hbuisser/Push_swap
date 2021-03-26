/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
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

    if (argc < 2 || (argc == 2 && (!ft_strncmp(argv[1], "-v", 2))))
        return (0);
    i = 1;
    if (!ft_strncmp(argv[1], "-v", 2))
        i = 2;
    init_struct(&data, argc, argv);
    if (check_digit(argc, argv, i) < 0)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    parse_stack(argv, &data, i);
    //data.nb_chunk = get_nbr_chunck()
    if (!ft_strncmp(argv[1], "-v", 2))
        debug(&data);
    return (1);
}