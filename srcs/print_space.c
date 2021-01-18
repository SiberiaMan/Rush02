/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 10:56:49 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 19:43:09 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_space_hundreds(t_tripple *arr, int index)
{
	if (index == 0 && arr[index].second == '0' && arr[index].third == '0')
		return ;
	else if (index != 0 && arr[index].second == '0' && arr[index].third == '0')
		write(1, " ", 1);
	else
		write(1, " ", 1);
}

void	print_space_tens_f(int index)
{
	if (index == 0)
		return ;
	else
		write(1, " ", 1);
}

void	print_space_tens_s(t_tripple *arr, int index)
{
	if (index == 0 && arr[index].third == '0')
		return ;
	else if (index != 0 && arr[index].third == '0')
		write(1, " ", 1);
	else
		write(1, " ", 1);
}

void	print_space_ones(int index)
{
	if (index == 0)
		return ;
	else
		write(1, " ", 1);
}

void	find_word(t_dict_data *data, int index)
{
	int i;

	i = 29;
	if (index == 0)
		return ;
	while (i < 41)
	{
		if (data[i].n_tripple == index)
		{
			ft_putstr(data[i].value);
			break ;
		}
		i++;
	}
}
