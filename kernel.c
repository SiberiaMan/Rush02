/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 07:14:32 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 19:43:15 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			find_hundreds(char c, t_dict_data *data)
{
	int i;

	if (c != data[0].key[0])
	{
		i = 1;
		while (i < 10)
		{
			if (c == data[i].key[0])
			{
				ft_putstr(data[i].value);
				write(1, " ", 1);
				ft_putstr(data[28].value);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int			find_tens_first(char second, t_dict_data *data)
{
	int i;

	i = 10;
	while (i < 20)
	{
		if (second == data[i].key[1])
		{
			ft_putstr(data[i].value);
			return (1);
		}
		i++;
	}
	return (0);
}

int			find_tens_second(char c, t_dict_data *data)
{
	int i;

	if (c != data[0].key[0])
	{
		i = 20;
		while (i < 28)
		{
			if (c == data[i].key[0])
			{
				ft_putstr(data[i].value);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int			find_ones(char c, t_dict_data *data)
{
	int i;

	if (c != data[0].key[0])
	{
		i = 1;
		while (i < 10)
		{
			if (c == data[i].key[0])
			{
				ft_putstr(data[i].value);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

void		kernel(t_tripple *arr, t_dict_data *data, int tripple_length)
{
	int begin;

	begin = tripple_length - 1;
	while (begin >= 0)
	{
		if (find_hundreds(arr[begin].first, data))
			print_space_hundreds(arr, begin);
		if (arr[begin].second == '1')
		{
			find_tens_first(arr[begin].third, data);
			print_space_tens_f(begin);
		}
		else if (find_tens_second(arr[begin].second, data))
			print_space_tens_s(arr, begin);
		if (find_ones(arr[begin].third, data))
			print_space_ones(begin);
		find_word(data, begin);
		if (begin != 0)
			write(1, " ", 1);
		begin--;
	}
	write(1, "\n", 1);
}
