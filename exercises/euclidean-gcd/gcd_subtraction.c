// Greatest common divisor (iterative subtraction method)

#include <stdio.h>

int gcd(int m, int n) {

   while (m != n) {
      if (m > n)
	 m = m-n;
      else
	 n = n-m;
   }
   return m;
}

int main(void) {

   printf("%d\n", gcd(30,18));
   return 0;
}
