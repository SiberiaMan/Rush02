/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 21:24:25 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 20:04:32 by sgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			ft_length(char *str, int i)
{
	int length;

	length = 0;
	while (str[i] != ',' && str[i] != '\0')
	{
		i++;
		length++;
	}
	return (length);
}

void		ft_strcpy_sort(char *str_valid, char *str, int cur_index)
{
	int i;

	i = 0;
	while (str_valid[cur_index] != ',')
		str[i++] = str_valid[cur_index++];
	str[i] = '\0';
}

void		ft_find_data(t_dict_data *data, char **srcs, char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	while (srcs[i])
	{
		j = 0;
		if (srcs[i][j] == str[0])
		{
			k = 0;
			while (srcs[i][j++] == str[k++])
				if ((srcs[i][j] == ':' || srcs[i][j] == ' ')
				&& str[k] == '\0')
				{
					store_data(data, srcs[i]);
					break ;
				}
		}
		i++;
	}
}

void		sort_struct(t_dict_data *data, char *str_valid, char **srcs,
		char **matrix)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	while (i < 41)
	{
		if (str_valid[j] == ',')
		{
			j++;
			continue;
		}
		length = ft_length(str_valid, j);
		matrix[i] = malloc(sizeof(char) * length + 1);
		ft_strcpy_sort(str_valid, matrix[i], j);
		ft_find_data(data, srcs, matrix[i]);
		data++;
		j += length;
		i++;
	}
}

void		pre_sort_struct(t_dict_data *data, char *namefile,
char *str_valid, char *str_dict)
{
	int		fd_dict;
	int		fd_valid;
	char	**srcs;
	char	**matrix;

	if (namefile == 0)
	{
		fd_dict = open("/home/phili/Desktop/Rush02/valid_dict", O_RDONLY);
		read(fd_dict, str_dict, 30000);
	}
	fd_valid = open("/home/phili/Desktop/Rush02/Mask", O_RDONLY);
	read(fd_valid, str_valid, 30000);
	srcs = (char **)malloc(sizeof(char*) * count_words(str_dict) + 1);
	matrix = (char **)malloc(sizeof(char*) * 42);
	ft_split(srcs, str_dict);
	sort_struct(data, str_valid, srcs, matrix);
	matrix[41] = 0;
	free_function(srcs, str_dict, str_valid, matrix);
}
