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

// define limits
# define INT_MAX 2147483647
# define INT_MIN -2147483646
# define LLONG_MAX 9223372036854775807
# define LLONG_MIN -9223372036854775806

# define BUFF_SIZE 50
# define START 1
# define END -1
# define FIRST 0
# define SECOND 1
# define ALL -1
# define MATH_PRECISION 0.000000001

typedef struct		linkedList
{
	void							*content;
	size_t						contentSize;
	struct linkedList	*next;
}										linkedList;

typedef struct				boundaryList
{
	size_t						  start;
	size_t						  end;
	struct boundaryList	*next;
}										  boundaryList;

typedef int t_bool;

char								*ft_strcfill(char *dest, char *src, const unsigned char c, size_t len);
char								*ft_strcjoinf(const char *s1, const char *s2, char c, int toFree);
int									ft_strcharsjoin(const char *s1, const char *s2, char *chars, int *charFoundIndex);
int									ft_strcharsjoinf(const char *s1, const char *s2, char *chars, int *charFoundIndex, int toFree);
char								*ft_realloc(char *str, size_t new_size);
char								*ft_strdupf(char *to_dup, char *to_free);
char								*ft_char_replace(char *str, char to_find, char replace_by);
char								*ft_strshift(char *str, int decale, int sens, size_t len);
int									ft_lllen(long long n, int no_sign);
char								*ft_lltoa(long long n);
char								*ft_ulltoa(unsigned long long n);
int									ft_stristr(const char *haystack, const char *needle);
char								**ft_strsplit(char const *s, char *charset);
int									ft_strsplitbyboundaries(char ***tabDest, const char *str, boundaryList *head, size_t lstLen, t_bool freeLst);
char								*ft_ldtoa(long double nbr);
char								*ft_strfill(char *str, char c, size_t n);
char								*ft_strnjoinf(const char *s1, const char *s2, size_t n, int to_free);
char								*ft_base_n_to_x_ull(char *nbr, char *base_from, char *base_to);
char								*ft_from_base_10_ull(unsigned long long nbr, char *base_to, int base_len);
unsigned long long	ft_to_base_10_ull(char *nbr, char *base_from, int base_len);
char								*ft_base_n_to_x(char *nbr, char *base_from, char *base_to);
char								*ft_strrev(char *str);
char								*ft_from_base_10(long long nbr, char *base_to, int base_len);
long long						ft_to_base_10(char *nbr, char *base_from, int base_len);
int									ft_power(int nb, int power);
double							ft_d_power(double nb, double power);
double							ft_di_power(double nb, int power);
double							ft_log(unsigned int nbr);
double							ft_root(int nthRoot, double nbr);
int									*ft_decimaltofraction(double nbr, int maxMagnitude);
int									ft_sqrt(int nb);
long double					ft_diff(long double d1, long double d2);
long double					ft_div(long double d1, long double d2);
void								ft_strtabcpy(char **dest, char **src, size_t src_size);
char								**ft_strtabdup(char **tab, size_t tab_size);
void								*ft_mallstrtab(size_t tab_size, size_t str_size);
char								**ft_reallocstrtab(char **tab, size_t old_size, size_t new_size);
int									ft_getFileContentAsList(const char *fileName, linkedList **head);
int									ft_getFileContentAsStr(const char *fileName, char **fileContent);
int									ft_getnextline(const int fd, char **line);
char								*ft_strndup(const char *s, size_t n);
char								*ft_strndel(char *s, int deleteSide, size_t indexToRemoveFrom);
char								*ft_strchrf(char *s, const unsigned char c);
int									ft_readfile(const char *filename, char ***dest);
char								*ft_strjoinf(const char *s1, const char *s2, int toFree);
int									ft_strichr(const char *s, const unsigned char c);
int									ft_strcharschr(const char *s, const char *chars);
char								*ft_strccpy(char *dest, const char *src, const unsigned char c);
size_t							ft_strlen(const char *str);
char								*ft_strdup(const char *s);
void								*ft_memset(void *s, int c, size_t n);
void								*ft_memmove(void *dest, const void *src, size_t n);
void								*ft_memcpy(void *dest, const void *src, size_t n);
void								*ft_memccpy(void *dest, const void *src, int c, size_t n);
void								*ft_memchr(const void *s, int c, size_t n);
int									ft_memcmp(const void *s1, const void *s2, size_t n);
void								*ft_memalloc(size_t size);
void								ft_bzero(void *s, size_t n);
void								ft_putstr(char const *s);
void								ft_putchar(char c);
void								ft_printstrtab(char **tab, int size);
void								ft_freestrtabn(char **tab, size_t size, int freeMainTab);
void								ft_freestrtab(char **tab);
void								ft_del(void *content, size_t contentSize);
void								ft_dummydel(void *content, size_t contentSize);
void								ft_blstdel(boundaryList **head);
void								ft_blstdelone(boundaryList **link);
void								ft_blstdelthis(boundaryList **head, boundaryList *toDel);
boundaryList				*ft_blstnew(size_t start, size_t end);
void								ft_blstpush(boundaryList **head, boundaryList **cursor, boundaryList *new);
void								ft_blstpushtop(boundaryList **head, boundaryList *new);
void								ft_lstdelthis(linkedList **head, linkedList *toDel, void (*del)(void *, size_t));
linkedList					*ft_lstfindor(linkedList *head, size_t cs, void *content);
linkedList					*ft_lstnew(void const *content, size_t contentSize);
void								ft_lstdelone(linkedList **link, void (*del)(void *, size_t));
void								ft_lstdel(linkedList **head, void (*del)(void *, size_t));
void								ft_lstpush(linkedList **head, linkedList **cursor, linkedList *new);
void								ft_lstpushtop(linkedList **head, linkedList *new);
void								ft_lstiter(linkedList *lst, void (*f)(linkedList *));
linkedList					*ft_lstmap(linkedList *lst, linkedList *(*f)(linkedList *));
int									ft_toupper(int c);
int									ft_tolower(int c);
char								*ft_strtrim(char const *s);
char								*ft_strsub(char const *s, unsigned int start, size_t len);
char								*ft_strstr(const char *haystack, const char *needle);
char								**ft_strcsplit(char const *s, const unsigned char c);
char								*ft_strrchr(const char *s, int c);
char								*ft_strchr(const char *s, const unsigned char c);
char								*ft_strnstr(const char *big, const char *little, size_t len);
char								*ft_strnew(size_t len);
int									ft_strnequ(char const *s1, char const *s2, size_t n);
char								*ft_strncpy(char *dest, const char *src, size_t n);
int									ft_strncmp(const char *s1, const char *s2, size_t n);
char								*ft_strncat(char *dest, const char *src, size_t n);
char								*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char								*ft_strmap(char const *s, char (*f)(char));
size_t							ft_strlcat(char *dest, const char *src, size_t size);
char								*ft_strjoin(char const *s1, char const *s2);
void								ft_striteri(char *s, void (*f)(unsigned int, char *));
void								ft_striter(char *s, void (*f)(char *));
int									ft_strequ(char const *s1, char const *s2);
void								ft_strdel(char **as);
char								*ft_strcpy(char *dest, const char *src);
int									ft_strcmp(const unsigned char *s1, const unsigned char *s2);
void								ft_strclr(char *s);
int									ft_atoi(const char *nptr);
long long						ft_atol(const char *nptr);
t_bool							ft_isalnum(char c);
t_bool							ft_isalpha(char c);
t_bool							ft_isascii(char c);
t_bool							ft_isdigit(char c);
t_bool							ft_isprint(char c);
void								ft_memdel(void **ap);
void								ft_putchar_fd(char c, int fd);
void								ft_putendl(char const *s);
void								ft_putendl_fd(char const *s, int fd);
void								ft_putnbr(int n);
void								ft_putnbr_fd(int n, int fd);
void								ft_putstr_fd(char const *s, int fd);
char								*ft_strcat(char *dest, const char *src);
void								ft_printinttab(int *tab, size_t size, int print_mode);
int									ft_intlen(int n);
char								*ft_itoa(int n);

#endif
