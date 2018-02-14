/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlriabts <hlriabts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 19:43:47 by hlriabts          #+#    #+#             */
/*   Updated: 2018/01/28 16:10:15 by hlriabts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CHECK_MAX(a,b) ((a) >= (b)) ? (a) : (b)
# define CHECK_MIN(a,b) ((a) >= (b)) ? (b) : (a)
# define ABS(a) ((a) < 0) ? -(a) : (a)
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <locale.h>
# include <wchar.h>

typedef struct			s_printf
{
	char				c;
	char				*flags;
	int					min_width;
	int					prec;
	char				cf;
	char				*pre_con;
	char				*ctent;
	int					dop_ind;
	struct s_printf		*next;
}						t_printf;
int						ft_printf(const char *format, ...);
wchar_t					*str_uni_null(wchar_t *s);
int						get_next_line(const int fd, char **line);
int						memory_calc(t_printf *l, int count, int base, int sign);
int						check_sign(t_printf *l, int sign, int i, int base);
int						print_list(t_printf **list);
void					printf_itoa (t_printf *l, size_t n,
						int base, int first_s);
void					*ft_join(char **str, char *str2);
int						pre_width(t_printf *l, int size, int count);
int						sign_hash(t_printf *l, int base, int sign, int count);
void					precision_check(t_printf *l);
int						width_count (t_printf *l, int sign,
						int count, int base);
void					int_printf(t_printf *l, size_t n, int sign);
void					pre_int(t_printf *l, va_list ap);
t_printf				*list_init (t_printf *list);
int						pre_con_cpy(const char *format, t_printf
						**list, int *start);
int						find_conv_prec_width(const char *format,
						int start, t_printf *list);
void					find_flags(const char *format, int start,
						int end, t_printf *list);
void					clear_lst(t_printf *list);
void					function_find(t_printf *list, va_list arguments);
unsigned char			*count_uni(int i, int count, unsigned char *res);
void					str_post_flag (t_printf *l);
unsigned char			*uni_char(int i);
void					uni_str(t_printf *l, wchar_t *buf, int k);
void					pre_char(t_printf *l, va_list ap, char *buf, char c);
#endif
