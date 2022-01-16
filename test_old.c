#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


# define FALSE 0
# define TRUE 1
# define ALL -1

size_t	ft_strlen(const char *str)
{
	unsigned long len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}


int		ft_strichr(const char *s, const unsigned char c)
{
  if (c == '\0')
    return !s ? 0 : ft_strlen(s);

	for (size_t i = 0; s[i] != '\0'; i++)
		if (s[i] == c) return (i);

	return (-1);
}

void	ft_freestrtabn(char **tab, size_t size, int freeMainTab)
{

	if (!tab || size == 0)
		return ;

	for (size_t i = 0; i < size && tab[i]; i++) {
		free(tab[i]);
		tab[i] = NULL;
	}

	if (freeMainTab)
		free(tab);
}

static int		ft_nbrwords(char const *s, char *charset)
{
	int		nbr_word;
	int		i;

	nbr_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && ft_strichr(charset, s[i]) != -1)
			i++;
		if (s[i] != '\0')
			nbr_word++;
		while (s[i] && ft_strichr(charset, s[1]) == -1)
			i++;
	}
	return (nbr_word);
}

static char		*ft_newword(char const *s, char *charset)
{
	char	*str;
	int		i;

  printf("truc\n");
	i = 0;
	while (s[i] && ft_strichr(charset, s[i]) == -1)
		i++;
  printf("mach %d [%c/%d]\n", i, s[i], s[i]);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1)))) {
    printf("on\n");
    return (NULL);
  }
	printf("text\n");
	i = 0;
  printf("....\n");
	while (s[i] && ft_strichr(charset, s[i]))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
  printf("qerzre\n");
	return (str);
}

static char		**ft_nullendtab(char **tab, int index)
{
	tab[index] = 0;
	return (tab);
}

static int		ft_test_and_set(int *n, int *i, char const *s, char *charset)
{
	if (!s || !charset)
		return (0);
	*n = 0;
	*i = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char *chars)
{
	char	**tab;
	int		index_w;
	int		i;

	if (ft_test_and_set(&i, &index_w, s, chars) == 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_nbrwords(s, chars) + 1))))
		return (NULL);
  printf("here\n");
	if (ft_nbrwords(s, chars) == 0)
		return (ft_nullendtab(tab, 0));
	while (s[i] != '\0')
	{
		while (s[i] && ft_strichr(chars, s[i]) != -1)
			i++;
    printf("there\n");
		if (s[i] != '\0')
		{
			if (!(tab[index_w] = ft_newword((char*)(&s[i]), chars))) {
        ft_freestrtabn(tab, index_w, TRUE);
				return (NULL);
      }
			index_w++;
		}
    printf("wesh\n");
		while (s[i] && ft_strichr(chars, s[i]) == -1)
  		i++;
	}
  printf("sisi\n");
	return (ft_nullendtab(tab, index_w));
}

void	ft_freestrtab(char **tab)
{
	if (!tab)
    return ;
	
	for (size_t i = 0; tab[i]; i++)
		free(tab[i]);

	free(tab);
}

int main(void) {
  char str[] = "<p>Lorem ipsum dolor sit amet.";

  int i = 0;
  for (i = 0; i < 1000; i++) {
    char **tab = ft_strsplit(str, "cit");
    ft_freestrtab(tab);
  }
  return 0;
}