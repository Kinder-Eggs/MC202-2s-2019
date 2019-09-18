#include <stdio.h>
//Gabriel Costa Kinder - 234720
int main() {
  printf("      +0 +1 +2 +3 +4 +5 +6 +7 \n");
  printf("    +------------------------ \n");
  int n = 32, i = 0;
  for (i = 0; i < 9; i++){
    printf(" %d |  %c  %c  %c  %c  %c  %c  %c  %c \n", n, n, n+1, n+2, n+3, n+4, n+5, n+6, n+7);
    n += 8;
  }
  for (; i < 11; i++){
    printf("%d |  %c  %c  %c  %c  %c  %c  %c  %c \n", n, n, n+1, n+2, n+3, n+4, n+5, n+6, n+7);
    n += 8;
  }
  printf("%d |  %c  %c  %c  %c  %c  %c  %c    \n", n, n, n+1, n+2, n+3, n+4, n+5, n+6);
}
