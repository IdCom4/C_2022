
#include <unistd.h>

void ft_printstr(char *str) {

  int len = 0;
  while (str[len] != '\0')
    len++;

  write(1, str, len);

}