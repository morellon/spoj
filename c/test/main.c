#include <stdio.h>

int main() {
   int i;
   scanf("%d", &i);
   while(i != 42) {
      printf("%d\n", i);
      scanf("%d", &i);
   }
   return 0;
}
