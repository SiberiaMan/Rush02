/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 00:05:20 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 20:05:11 by sgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_strlen_data(char *str, int fl)
{
	int length;

	length = 0;
	if (fl == 1)
	{
		while (*str && *str != ' ' && *str != ':')
		{
			length++;
			str++;
		}
		return (length);
	}
	else
	{
		while (*str && *str != '\n')
		{
			length++;
			str++;
		}
		return (length);
	}
}

int			value_index(int cur_in, char *srcs)
{
	if (srcs[cur_in] == ':')
		cur_in++;
	else if (srcs[cur_in] == ' ')
	{
		while (srcs[cur_in] != ':')
			cur_in++;
		cur_in++;
	}
	while (!(' ' < srcs[cur_in] && srcs[cur_in] <= '~'))
		cur_in++;
	return (cur_in);
}

int			fill_data_first(t_dict_data *data, int size, char *srcs)
{
	int i;

	i = 0;
	while (i < size)
	{
		(data->key)[i] = srcs[i];
		i++;
	}
	(data->key)[i] = '\0';
	return (i);
}

void		fill_data_last(t_dict_data *data, char *srcs, int index)
{
	int j;
	int fl;

	j = 0;
	fl = 0;
	while (srcs[index] != '\n' && srcs[index] != '\0')
	{
		if (' ' < srcs[index] && srcs[index] <= '~' && !fl)
			(data->value)[j++] = srcs[index++];
		else if (' ' < srcs[index] && srcs[index] <= '~' && fl)
		{
			(data->value)[j++] = ' ';
			(data->value)[j++] = srcs[index++];
			fl = 0;
		}
		else if (srcs[index] == ' ' || srcs[index] == '\t')
		{
			fl = 1;
			index++;
		}
	}
	(data->value)[j] = '\0';
}

void		store_data(t_dict_data *data, char *srcs)
{
	int size;
	int i;

	size = ft_strlen_data(srcs, 1);
	data->key = (char *)malloc(sizeof(char) * size + 1);
	i = fill_data_first(data, size, srcs);
	i = value_index(i, srcs);
	size = ft_strlen_data(srcs + i, 2);
	data->value = (char *)malloc(sizeof(char) * size + 1);
	fill_data_last(data, srcs, i);
	data->n_tripple = 0;
}
