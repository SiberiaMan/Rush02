/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:09:24 by dchani            #+#    #+#             */
/*   Updated: 2020/08/30 20:56:38 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_dict_data
{
	char		*key;
	char		*value;
	int			n_tripple;
}				t_dict_data;

typedef struct	s_tripple
{
	char		first;
	char		second;
	char		third;
}				t_tripple;

void			algorithm(t_tripple *arr, t_dict_data *data, char *str);
int				ft_strcmp(char *s1, char *s2);
int				check_data(t_dict_data *data);
int				valid_str(char *str, int cur_in);
int				valid_dict(char *str);
int				enter_dict(char *str_dict);
void			fill_numbers_data(t_dict_data *data);
void			free_function(char **srcs, char *str_dict,
				char *str_valid, char **matrix);
void			ft_putstr(char *str);
int				count_words(char *str);
int				ft_strlen_split(char *str_dict, int i);
void			ft_strcpy_split(char *str_to, char *str_from, int cur_index);
void			ft_split(char **srcs, char *str_dict);
void			init_tripple(t_tripple *arr, int tripple_length);
int				find_hundreds(char c, t_dict_data *data);
int				find_tens_first(char second, t_dict_data *data);
int				find_tens_second(char c, t_dict_data *data);
int				find_ones(char c, t_dict_data *data);
void			kernel(t_tripple *arr, t_dict_data *data, int tripple_length);
int				ft_length(char *str, int i);
void			ft_strcpy_sort(char *str_valid, char *str, int cur_index);
void			ft_find_data(t_dict_data *data, char **srcs, char *str);
void			sort_struct(t_dict_data *data, char *str_valid, char **srcs,
				char **matrix);
void			pre_sort_struct(t_dict_data *data, char *str_valid, char
*str_dict);
int				ft_strlen_data(char *str, int fl);
int				value_index(int cur_in, char *srcs);
int				fill_data_first(t_dict_data *data, int size, char *srcs);
void			fill_data_last(t_dict_data *data, char *srcs, int index);
void			store_data(t_dict_data *data, char *srcs);
void			dividing(t_tripple *arr, int length, int tripples, char *str);
void			print_space_hundreds(t_tripple *arr, int index);
void			print_space_tens_f(int index);
void			print_space_tens_s(t_tripple *arr, int index);
int			f_s(char *s);
void			print_space_ones(int index);
void			find_word(t_dict_data *data, int index);
int				check_value(char *str);
void			to_alg(t_tripple *arr, t_dict_data *data, char *str);

#endif
