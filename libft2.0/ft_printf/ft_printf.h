/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:47:13 by idcornua          #+#    #+#             */
/*   Updated: 2019/04/16 17:34:36 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

# define TRUE 1
# define FALSE 0
# define UNSET -1
# define TO_GET -2
# define BAD_V -3
# define MOD 1
# define MAX_NBR_OPTIONS 8

# define NBR_COLORS 30
# define COLOR_CODES1 "\033[0;31m \033[1;31m \033[0;32m \033[1;32m \033[0;33m"
# define COLOR_CODES2 " \033[1;33m \033[0;34m \033[1;34m \033[0;35m \033[1;35m"
# define COLOR_CODES3 " \033[0;36m \033[1;36m \033[0m \e[0;40m \e[1;40m"
# define COLOR_CODES4 " \e[0;41m \e[1;41m \e[0;42m \e[1;42m \e[0;43m \e[1;43m"
# define COLOR_CODES5 " \e[0;44m \e[1;44m \e[0;45m \e[1;45m \e[0;46m \e[1;46m"
# define COLOR_CODES6 " \e[0;47m \e[1;47m \e[0m"
# define COLORS1 "{RED} {D_RED} {GREEN} {D_GREEN} {YELL} {D_YELL} {BLUE}"
# define COLORS2 " {D_BLUE} {PINK} {D_PINK} {CYAN} {D_CYAN} {CLEAR} {B_BLACK}"
# define COLORS3 " {BB_BLACK} {B_RED} {BB_RED} {B_GREEN} {BB_GREEN} {B_YELL}"
# define COLORS4 " {BB_YELL} {B_BLUE} {BB_BLUE} {B_PURPLE} {BB_PURPLE} {B_CYAN}"
# define COLORS5 " {BB_CYAN} {B_WHITE} {BB_WHITE} {B_CLEAR}"

# define OPTION_C "-+0 #=!/\0"
# define TYPE_C "diouxXfcspbB\0"
# define SIZE_C "lLh\0"

# define MINUS 0
# define PLUS 1
# define ZERO 2
# define SPACE 3
# define HTAG 4
# define INDEX 5
# define LINE 6
# define H_INDEX 7

# define LOW_L 0
# define LL 1
# define UP_L 2
# define H 3
# define HH 4

# define T_LL long long *
# define T_ULL unsigned long long *
# define T_LD long double *

typedef struct		s_flags
{
	int				options[MAX_NBR_OPTIONS];
	int				min_width;
	int				repeat;
	int				precision;
	int				format;
	int				t_size;
	int				size;
	char			type;
	int				option_len;
	int				mod;
	int				color;
	int				color_index;
	char			*base_from;
	char			*base_to;
	int				len_base_from;
	int				len_base_to;
	int				x_format;
	char			*x_start;
	int				l_x_start;
	char			*x_mid;
	int				l_x_mid;
	char			*x_end;
	int				l_x_end;
	int				y_format;
	char			y_start;
	char			y_mid;
	char			y_end;
	struct s_flags	*next;
}					t_flags;

void				get_to_get(va_list ap, t_flags *curr);

t_flags				*get_color(t_flags *flags, char *str);
char				*get_color_code(t_flags *cursor);

char				**ft_t_b(va_list ap, t_flags *curr, int t_size, int size);
char				**ft_b_b(va_list ap, int t_size, t_flags *f);
char				**ft_gb_llb(va_list ap, int t_size, t_flags *f);
char				**ft_gb_lb(va_list ap, int t_size, t_flags *f);
char				**ft_gb_gb(va_list ap, int t_size, t_flags *f);

char				**ft_o_o(int t_size, va_list ap);
char				**ft_o_l(int t_size, va_list ap);
char				**ft_o_ll(int t_size, va_list ap);
char				**ft_o_h(int t_size, va_list ap);
char				**ft_o_hh(int t_size, va_list ap);

char				**ft_u_u(int t_size, va_list ap);
char				**ft_u_l(int t_size, va_list ap);
char				**ft_u_ll(int t_size, va_list ap);
char				**ft_u_h(int t_size, va_list ap);
char				**ft_u_hh(int t_size, va_list ap);

char				**ft_x_x(int t_size, va_list ap);
char				**ft_x_l(int t_size, va_list ap);
char				**ft_x_ll(int t_size, va_list ap);
char				**ft_x_h(int t_size, va_list ap);
char				**ft_x_hh(int t_size, va_list ap);

char				**ft_gx_gx(int t_size, va_list ap);
char				**ft_gx_l(int t_size, va_list ap);
char				**ft_gx_ll(int t_size, va_list ap);
char				**ft_gx_h(int t_size, va_list ap);
char				**ft_gx_hh(int t_size, va_list ap);

char				**ft_d_d(int t_size, va_list ap);
char				**ft_d_l(int t_size, va_list ap);
char				**ft_d_ll(int t_size, va_list ap);
char				**ft_d_h(int t_size, va_list ap);

char				**ft_f_f(int t_size, va_list ap);
char				**ft_f_d(int t_size, va_list ap);
char				**ft_f_ld(int t_size, va_list ap);

char				*spec_arrondi(char *value, int nbr_digit, int *prec, int n);
char				*ft_arrondi(char *value, int preci, int nbr_i, int n);
char				*ft_decimal_preci(char *value, int n, int v_len);
char				*nb_format(char *value, t_flags *f, int len);
char				*ft_repeat(char *ret, int rep);
char				*ft_precision(int precision, char type, char *val, int len);

char				*ft_d(int size, va_list ap);
char				*ft_o(int size, va_list ap);
char				*ft_u(int size, va_list ap);
char				*ft_x(int size, va_list ap);
char				*ft_gx(int size, va_list ap);
char				*ft_f(int size, va_list ap);
char				*ft_c(int size, va_list ap);
char				*ft_s(int size, va_list ap);
char				*ft_p(int size, va_list ap);
char				*ft_b(va_list ap, t_flags *curr, int size);
char				*get_param(va_list ap, t_flags *cursor);
char				**ft_t_d(int t_size, int size, va_list ap);
char				**ft_t_o(int t_size, int size, va_list ap);
char				**ft_t_u(int t_size, int size, va_list ap);
char				**ft_t_x(int t_size, int size, va_list ap);
char				**ft_t_gx(int t_size, int size, va_list ap);
char				**ft_t_f(int t_size, int size, va_list ap);
char				**ft_t_c(int t_size, int size, va_list ap);
char				**ft_t_s(int t_size, int size, va_list ap);
char				**ft_t_p(int t_size, int size, va_list ap);
char				**get_tab(va_list ap, t_flags *curr);

char				*ft_set_h_index(char *str, t_flags *f, int max_len);
char				*ft_tab(t_flags *cursor, va_list ap);

int					ft_error();
char				*ft_strjoinfe(char *s1, char *s2, int to_free);
char				*ft_strnjoinfe(char *s1, char *s2, size_t n, int to_free);
char				*ft_strcjoinfe(char *s1, char *s2, char c, int to_free);
char				*ft_strndupe(char *str, size_t n);
char				*ft_strjoine(char *s1, char *s2);
char				*ft_strndupe(char *str, size_t n);
char				*ft_strdupe(char *str);
char				*ft_strdupfe(char *to_dup, char *to_free);

t_flags				*ft_new_flag(char const *str);
t_flags				*uniform(t_flags *flags);
t_flags				*check_neg(t_flags *f);

int					ft_skip(char *str);
int					get_precision(char *str, t_flags *flags);
int					get_format(char *str, t_flags *flags);
char				*set_y_mid(t_flags *f, char *str, char *new, int len);
char				*set_y_end(char *str, char *new, t_flags *f, int len);
int					get_xy_format(char *str, t_flags *flags);
int					get_t_size(char *str, t_flags *flags);
int					get_min_width(char *str, t_flags *flags);
int					get_repeat(char *str, t_flags *flags);
int					get_options(char *str, t_flags *flags);
int					get_base(char *str, t_flags *flags);
int					get_size(char *str, t_flags *flags);
char				*ft_format_param(t_flags *flags, char *value);
void				ft_parse_format(char const *format, t_flags **head);
void				ft_print_lst(t_flags *flag);
void				ft_freeflags(t_flags **head);

void				ft_algo(char *fmt, char **print, t_flags *cursor,
					va_list ap);

int					ft_printf(char const *format, ...);
int					ft_sprintf(char **dest, char const *format, ...);
int					ft_fdprintf(int fd, char const *format, ...);
#endif
