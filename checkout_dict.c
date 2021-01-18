/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkout_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:45:18 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 15:02:49 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			valid_str(char *str, int cur_in)
{
	while ('0' <= str[cur_in] && str[cur_in] <= '9')
		cur_in++;
	while (str[cur_in] == ' ' || str[cur_in] == '\t')
		cur_in++;
	if (str[cur_in] != ':')
		return (0);
	else
		cur_in++;
	while (str[cur_in] == ' ' || str[cur_in] == '\t')
		cur_in++;
	while (' ' <= str[cur_in] && str[cur_in] <= '~')
		cur_in++;
	if (str[cur_in] == '\n' || str[cur_in] == '\0')
		return (cur_in);
	else
		return (0);
}

int			valid_dict(char *str)
{
	int i;
	int valid;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			continue;
		}
		valid = valid_str(str, i);
		if (!valid)
			return (0);
		i = valid;
	}
	return (1);
}

int			enter_dict(char *namefile, char *str_dict)
{
	int fd;

	fd = open(namefile, O_RDONLY);
	if (fd == -1 || !read(fd, str_dict, 30000) || !valid_dict(str_dict))
		return (0);
	return (1);
}
