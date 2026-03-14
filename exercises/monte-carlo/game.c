// Simulation of a dice gambling game
// Rules:
// * pay $1, roll two 6-sided dice and add up values
// * if 2 <= total <= 7, lose money
// * if 8 <= total <=11, win $2
// * if total == 12, win $6
// Start with $5 ... stop when balance == $0 or balance >= $20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRIALS 10000

int main(void) {
   int nwins = 0;
   int totlength = 0;

   srand(time(NULL));
   int i;
   for (i = 0; i < TRIALS; i++) {
      printf("Starting game...\n");

      int balance = 5;
      int length = 0;
      while (balance > 0 && balance < 20) {
         balance--;
         length++;
         int die1 = (rand() % 6) + 1;
         int die2 = (rand() % 6) + 1;
         printf("Outcome: %2d. ", die1+die2);
         if (die1+die2 <= 7) {
            ; // you lose
         } else if (die1+die2 <= 11) {
            balance += 2;
         } else {
            balance += 6;
         }
         printf("New balance: %d\n", balance);
      }
      totlength += length;
      if (balance >= 20) {
         nwins++;
      }
      putchar('\n');
   }
   printf("Chance of winning: %0.4f\n", nwins/(double)TRIALS);
   printf("Average game length: %0.1f\n", totlength/(double)TRIALS);
   return 0;
}
