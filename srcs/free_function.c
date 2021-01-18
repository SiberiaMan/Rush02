/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 05:04:51 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 19:57:20 by sgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		free_function(char **srcs, char *str_dict, char *str_valid,
	char **matrix)
{
	int i;

	i = 0;
	while (srcs[i])
	{
		free(srcs[i]);
		i++;
	}
	free(srcs[i]);
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	free(str_dict);
	free(str_valid);
}
