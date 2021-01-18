/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:44:55 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 19:27:35 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			f_s(char *str)
{
	int length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}

void		dividing(t_tripple *arr, int length, int tripples, char *str)
{
	int i;
	int index_l;

	i = 0;
	index_l = length - 1;
	while (i < tripples)
	{
		if (index_l >= 0)
		{
			arr[i].third = str[index_l];
			index_l--;
		}
		if (index_l >= 0)
		{
			arr[i].second = str[index_l];
			index_l--;
		}
		if (index_l >= 0)
		{
			arr[i].first = str[index_l];
			index_l--;
		}
		i++;
	}
}
