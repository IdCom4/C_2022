#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void ft_putstr(char *str);

int ft_is_corner(int x, int y, int width, int height) {

  if ((x == 0 || x == width - 1) && (y == 0 || y == height - 1))
    return TRUE;

  return FALSE;

}

void ft_colle(int width, int height) {

  char *str = malloc(sizeof(char) * ((width + height) * height + 1));

  if (str == NULL) return;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (ft_is_corner(x, y, width, height) == TRUE)
        str[(width + 1) * y + x] = 'o';
      else if (y == 0 || y == height - 1)
        str[(width + 1) * y + x] = '-';
      else if (x == 0 || x == width - 1)
        str[(width + 1) * y + x] = '|';
      else
        str[(width + 1) * y + x] = ' ';
    }
    str[(width + 1) * y + width] = '\n';
  }

  str[(width + height) * height] = '\0';

  ft_putstr(str);

  free(str);

}