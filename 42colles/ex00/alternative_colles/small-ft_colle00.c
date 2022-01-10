#include <stdlib.h>

void ft_putstr(char *str);

void ft_colle(int width, int height) {

  char *str = malloc(sizeof(char) * ((width + height) * height + 1));
  if (str == NULL) return;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (x == 0 || x == width - 1)
        str[(width + 1) * y + x] = (y == 0 || y == height - 1) ? 'o' : '|';
      else
        str[(width + 1) * y + x] = (y == 0 || y == height - 1) ? '-' : ' ';
    }
    str[(width + 1) * y + width] = '\n';
  }

  str[(width + height) * height] = '\0';

  ft_putstr(str);

  free(str);

}