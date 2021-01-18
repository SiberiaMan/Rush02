/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 04:09:17 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 19:59:42 by sgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int argc, char *argv[])
{
	char				*str_valid;
	char				*str_dict;
	t_dict_data			*data;
	t_tripple			*arr;

	(void)argc;
	arr = 0;
	data = malloc(sizeof(t_dict_data) * 41);
	str_valid = malloc(sizeof(char) * 30000);
	str_dict = malloc(sizeof(char) * 30000);
	if (!enter_dict(str_dict))
		write(1, "Dict Error\n", 11);
	pre_sort_struct(data, str_valid, str_dict);
	algorithm(arr, data, argv[1]);
	return (0);
}
