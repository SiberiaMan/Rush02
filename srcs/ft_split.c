/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 23:03:31 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 16:47:17 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			count_words(char *str)
{
	int res;
	int flag;

	res = 0;
	flag = 0;
	while (*str)
	{
		if (*str != '\n' && flag == 0)
		{
			flag = 1;
			res++;
		}
		else if (*str == '\n')
			flag = 0;
		str++;
	}
	return (res);
}

int			ft_strlen_split(char *str_dict, int i)
{
	int		res;

	res = 0;
	while (str_dict[i] != '\n' && str_dict[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}

void		ft_strcpy_split(char *str_to, char *str_from, int cur_index)
{
	int i;

	i = 0;
	while (str_from[cur_index] != '\n' && str_from[cur_index] != '\0')
		str_to[i++] = str_from[cur_index++];
	str_to[i] = '\0';
}

void		ft_split(char **srcs, char *str_dict)
{
	int size;
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str_dict[i] != '\0')
	{
		if (str_dict[i] == '\n')
		{
			i++;
			continue;
		}
		size = ft_strlen_split(str_dict, i);
		srcs[j] = (char*)malloc(sizeof(char) * size + 1);
		ft_strcpy_split(srcs[j], str_dict, i);
		i += size;
		j++;
	}
	srcs[j] = 0;
}
