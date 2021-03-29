
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
    int         i;
    int         init_len;
    int         len_a;
    int         len_b;
    char        *line;
    int			*a;
	int 		*b;
    int         *chunk_step;
    int         string_bool;
    int         nb_chunk;
    int         len_chunk;
    int         *sorted_arr;
}               t_data;

/*
*** UTILS
*/

void init_struct(t_data *data, int argc, char **argv);
int check_double(t_data *data, char **argv);
int parse_stack_string(t_data *data, char **argv, int argc, int i);
int parse_stack(t_data *data, char **argv, int argc);
int	check_digit(int argc, char **argv, int i);
int debug(t_data *data);
int	check_int_min_max(char *str);
int check_max(t_data *data, int nb, char **argv);
int already_in_order(t_data *data);
int	put_v_and_check(t_data *data, char **argv, int argc);
int	parse(t_data *data, char **argv, int argc);
void bring_above(t_data *data);
int free_all(t_data *data);
void free_tab(char **tab);

void	printArray(int *arr, int size);

/*
*** HARD
*/

int	hard_2(t_data *data);
int	hard_3_bis(t_data *data);
int	hard_3(t_data *data);
int	hard_4(t_data *data);
int	hard_5(t_data *data);

/*
*** ALGO PUSH
*/

int main_algo(t_data *data);
int push_to_b(t_data *data);
int push_to_a(t_data *data);
int compare_with_chunk_and_push(t_data *data, int iter);
int small_bash(t_data * data);

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