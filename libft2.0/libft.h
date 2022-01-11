/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idcornua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:50:59 by idcornua          #+#    #+#             */
/*   Updated: 2019/07/12 14:44:02 by idcornua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

# define BUFF_SIZE 50
# define START 1
# define END -1
# define FIRST 0
# define SECOND 1
# define ALL -1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strcfill(char *dest, char *src, char c, int size);
char				*ft_strcjoinf(const char *s1, const char *s2, char c,
					int to_free);
char				*ft_realloc(char *str, size_t new_size);
char				*ft_strdupf(char *to_dup, char *to_free);
char				*ft_char_replace(char *str, char to_find, char replace_by);
char				*ft_strdecale(char *str, int decale, int sens, int len);
int					ft_lllen(long long n, int no_sign);
char				*ft_lltoa(long long n);
char				*ft_ulltoa(unsigned long long n);
int					ft_stristr(const char *haystack, const char *needle);
char				**ft_chars_split(char const *s, char *charset);
char				*ft_ldtoa(long double nbr);
char				*ft_strfill(char *str, char c, size_t n);
char				*ft_strnjoinf(const char *s1, const char *s2, size_t n,
					int to_free);
char				*ft_base_n_to_x_ull(char *nbr, char *base_from,
					char *base_to);
char				*ft_from_base_10_ull(unsigned long long nbr, char *base_to,
					int base_len);
unsigned long long	ft_to_base_10_ull(char *nbr, char *base_from,
					int base_len);
char				*ft_base_n_to_x(char *nbr, char *base_from, char *base_to);
char				*ft_strrev(char *str);
char				*ft_from_base_10(long long nbr, char *base_to,
					int base_len);
long long			ft_to_base_10(char *nbr, char *base_from, int base_len);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
long double			ft_diff(long double d1, long double d2);
long double			ft_div(long double d1, long double d2);
void				ft_strtabcpy(char **dest, char **src, size_t src_size);
char				**ft_strtabdup(char **tab, size_t tab_size);
void				*ft_mallstrtab(size_t tab_size, size_t str_size);
char				**ft_reallocstrtab(char **tab, size_t old_size,
					size_t new_size);
int					get_next_line(const int fd, char **line);
void				ft_lstdelthis(t_list **head, t_list *t_del);
t_list				*ft_lstfindor(t_list *head, size_t cs, void *content);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strndel(char *s, int direction, size_t to_remove);
char				*ft_strchrf(char *s, int c);
int					ft_readfile(char *filename, char ***dest);
char				*ft_strjoinf(const char *s1, const char *s2, int to_free);
int					ft_strichr(const char *s, int c);
char				*ft_strccpy(char *dest, const char *src, int c);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				ft_printstrtab(char **tab, int size);
void				ft_freestrtabn(char **tab, size_t size, int freeMainTab);
void				ft_freestrtab(char **tab);
void				ft_del(void *content, size_t content_size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strnew(size_t size);
char				*ft_strnewclean(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
int					ft_strequ(char const *s1, char const *s2);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
int					ft_atoi(const char *nptr);
long long			ft_atol(const char *nptr);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				ft_memdel(void **ap);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dest, const char *src);
void				ft_printinttab(int *tab, size_t size, int print_mode);
int					ft_intlen(int n);
char				*ft_itoa(int n);

#endif
