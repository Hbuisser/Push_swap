/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-eyn <mvan-eyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:34:40 by mvan-eyn          #+#    #+#             */
/*   Updated: 2020/11/25 19:50:22 by mvan-eyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	**ft_megafree(char **tab, int y)
{
	while (--y >= 0)
		free(tab[y]);
	free(tab);
	return (NULL);
}

static int	ft_len_to_sep(char const *str, char c)
{
	int		i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_count_words(char const *str, char c)
{
	int	count;
	int	pos;

	if (str == NULL)
		return (0);
	count = 1;
	if (str[0] == c)
		count = 0;
	pos = 0;
	while (str[pos] && str[pos + 1])
	{
		if (str[pos] == c && str[pos + 1] != c)
			count++;
		pos++;
	}
	return (count);
}

static char	*ft_tmp_str(const char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (ft_len_to_sep(str, c) + 1));
	if (tmp)
	{
		while (str[i] != c && str[i] != '\0')
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		y;
	char	**split;

	i = 0;
	y = 0;
	split = malloc(sizeof(char *) * (ft_count_words(str, c) + 1));
	if (str == NULL || split == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			split[y] = ft_tmp_str(&str[i], c);
			if (!split[y])
				return (ft_megafree(split, y));
			i = i + ft_len_to_sep(&str[i], c);
			y++;
		}
		else if (str[i] == c)
			i++;
	}
	split[y] = NULL;
	return (split);
}
