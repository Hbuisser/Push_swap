/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:33:37 by hbuisser          #+#    #+#             */
/*   Updated: 2021/03/01 13:45:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	init_struct(t_data *data, int argc, char **argv)
{
	data->i = 1;
	data->line = ft_strdup("");
	data->nb_chunk = 0;
	data->len_chunk = 0;
	data->init_len = argc - 1;
	if (argv[1] && !ft_strncmp(argv[1], "-v", 2))
		data->init_len -= 1;
	data->len_b = 0;
	data->string_bool = 0;
}
