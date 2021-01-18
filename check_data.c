/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 03:21:57 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 14:17:13 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int			check_data(t_dict_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < 41)
	{
		j = 0;
		while (j < 41)
		{
			if (j != i && !ft_strcmp(data[i].value, data[j].value))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
