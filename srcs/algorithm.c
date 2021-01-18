/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 04:11:18 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 20:58:55 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	algorithm(t_tripple *arr, t_dict_data *data, char *str)
{
	int length;
	int tripple_length;

	length = f_s(str);
	tripple_length = length / 3 + (length % 3 > 0);
	arr = malloc(sizeof(t_tripple) * tripple_length);
	init_tripple(arr, tripple_length);
	dividing(arr, length, tripple_length, str);
	fill_numbers_data(data);
	if (check_value(str) && (('0' < str[0] && str[0] <= '9')
	|| (str[0] == '0' && f_s(str) == 1)))
	{
		if (str[0] == '0')
		{
			ft_putstr(data[0].value);
			write(1, "\n", 1);
		}
		else
			kernel(arr, data, tripple_length);
	}
	else
		write(1, "Error\n", 6);
	free(data);
	free(arr);
}
