#define TRUE 1
#define FALSE 0

void ft_putchar(char c);

int ft_is_corner(int x, int y, int width, int height) {

  if ((x == 0 || x == width - 1) && (y == 0 || y == height - 1))
    return TRUE;

  return FALSE;

}

void ft_colle(int width, int height) {

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (ft_is_corner(x, y, width, height) == TRUE)
        ft_putchar('o');
      else if (y == 0 || y == height - 1)
        ft_putchar('-');
      else if (x == 0 || x == width - 1)
        ft_putchar('|');
      else
        ft_putchar(' ');
    }
    ft_putchar('\n');
  }

}