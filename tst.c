#include <stdbool.h>
#include <stdio.h>
#define DEBUGTAG 0

int main ()
{
   #if DEBUGTAG
      printf("DEBUG TAG ON\n");
   #endif
      printf("Some text..... \n");
}
