/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tripple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 07:07:20 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 19:11:45 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		init_tripple(t_tripple *arr, int tripple_length)
{
	int i;

	i = 0;
	while (i < tripple_length)
	{
		arr[i].first = '0';
		arr[i].second = '0';
		arr[i].third = '0';
		i++;
	}
}
