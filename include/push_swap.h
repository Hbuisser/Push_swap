
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 09:16:31 by mvan-eyn          #+#    #+#             */
/*   Updated: 2021/02/23 19:55:32 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# include "../utils/libft/include/libft.h"

typedef struct  s_data
{
    int         init_len;
    int         len_a;
    int         len_b;
    char        *line;
    int			*a;
	int 		*b;
    int         string_bool;
    int         nb_chunk;
}               t_data;

/*
*** UTILS
*/

void init_struct(t_data *data, int argc, char **argv);
int parse_stack(char **argv, t_data *data, int j);
int	check_digit(int argc, char **argv, int i);
int debug(t_data *data);

/*
*** INSTRUCTIONS
*/

void sa(t_data *data);
void sb(t_data *data);
void ss(t_data *data);
int pa(t_data *data);
int pb(t_data *data);
int ra(t_data *data);
int rb(t_data *data);
int rr(t_data *data);
int rra(t_data *data);
int rrb(t_data *data);
int rrr(t_data *data);

#endif