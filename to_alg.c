/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:44:33 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 14:55:07 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	to_alg(t_tripple *arr, t_dict_data *data, char *str)
{
	if (!check_data(data))
		write(1, "Dict Error\n", 11);
	else
		algorithm(arr, data, str);
}
