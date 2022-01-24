#include <stdio.h>
#include <stdlib.h>

# define PRECISION 0.000000001
# define DOUBLE_END_CLEAR_FACTOR 100000

# define DECREASE 0
# define INCREASE 1

# define FALSE 0
# define TRUE 1

double  ft_clearDoubleEnd(double d) {
  int intPart = (int)d;
  double endPart = d - intPart;

  // to remove unwanted double end fluctuations (like 0.00000000000000010)
  endPart = (double)((int)(endPart * DOUBLE_END_CLEAR_FACTOR)) / DOUBLE_END_CLEAR_FACTOR;

  return (double)intPart + endPart;
}

int ft_isInt(double d) {
  // d = ft_clearDoubleEnd(d);

  long long lld = d;

  if ((double)lld == d || d - (double)lld <= PRECISION)
    return TRUE;
  return FALSE;
}

double ft_di_power(double nbr, int power) {
  double result = 1.0;

  while (power--) {
    result *= nbr;
    //printf("r = %.20f\n", result);
  }
   
  
  return result;
}

// ft_root(nthRoot, nbr) = if (x ^ nthRoot == nbr) return x

double ft_root(int nthRoot, double nbr){
  double root = 2;
  double stepSize = 0.5;
  double powerResult = 0;
  

  // get root to less than 1 too high
  long long llPowerResult;
  while ((llPowerResult = ft_di_power(root, nthRoot)) < nbr && root < 46341)
    root++;
  
  if (llPowerResult == nbr)
    return llPowerResult;

  // means numbers are too high to be computed
  if (root >= 46341)
    return -1;

  root -= stepSize;
  /*  root -= (pow(root, (double)nthRoot) - nbr) / ( nthRoot * pow(root, (double)(nthRoot - 1)) );
  1 -= ((1 ^ 10 - 2) / (10 * 1 ^ 9))
  1 -= (1 - 2) / (10 * 1)
  1 -= -1 / 10
  1 -= -0.1
  1.1

  1.1 -= ((1.1 ^ 10 - 2) / (10 * 1.1 ^ 9))
  1.1 -= (2.5937424601 - 2) / (10 * 2.357947691)
  1.1 -= 0.5937424601 / 23.57947691
  1.1 -= 0.02518047632
  1.07481952368 */

  while (stepSize >= PRECISION) {
      stepSize *= 0.5;

      powerResult = ft_di_power(root, nthRoot);
      if (powerResult == nbr)
        return root;
      if (powerResult > nbr)
        root -= stepSize;
      else
        root += stepSize;
  }

  return root;
}

int  *ft_decimalToFraction(double nbr, int maxMagnitude) {
  int magnitude = 1;

  while (!ft_isInt(nbr) && magnitude < maxMagnitude) {
    nbr *= 10;
    magnitude *= 10;
  }

  static int result[2];
  result[0] = nbr;
  result[1] = magnitude;

  return result;
}

double ft_d_power(double nbr, double power) {
  if (ft_isInt(power)) {
    return ft_di_power(nbr, power);
  }
  
  int     powerInt = (int)power;
  double  powerRest = power - powerInt;

  int *fraction = ft_decimalToFraction(powerRest, 10);

  printf("fraction: [%d, %d]\n", fraction[0], fraction[1]);

  double p1 = ft_di_power(nbr, powerInt);
  // printf("p1: %f\n", p1);
  double p2 = ft_di_power(nbr, fraction[0]);
  // printf("p2: %f\n", p2);
  double root = ft_root(fraction[1], p2);
  printf("p1: %f | p2: %f | root: %f\n", p1, p2, root);

  return p1 * root;
  // return  ft_di_power(nbr, powerInt) * ft_root(fraction[1], ft_di_power(nbr, fraction[0])); 

}

// ft_log(x) = if (r ^ n == x) return n

double  ft_log(unsigned int nbr) {
  if (nbr == 10)
    return 1;

  double  stepSize = 0.5;
  double  log = 1;

  if (nbr > 10) {
    unsigned int nb = nbr;
    while (nb > 10) {
      nb *= 0.1;
      log++;
    }
    if (nb == 10)
      return log;
  }

  log -= stepSize;

  // here we know that log is to high from less than 1
  while (stepSize >= PRECISION) {
    stepSize *= 0.5;

    double powerResult = ft_d_power(10, log);
    printf(" pr: %.20f\n", powerResult);
    printf(" log: %.20f\n", log);
    printf(" <: %d\n", powerResult < (double)nbr);

    if (powerResult == (double)nbr)
      return powerResult;
    else if (powerResult > (double)nbr)
      log -= stepSize;
    else
      log += stepSize;
  }

  return log;
}

int main() {
  // double r = ft_d_power(7, 4.2);

  double l = ft_log(15);

  // printf("r = %f\n", r);
  printf("log: %f\n", l);
  return 0;
}