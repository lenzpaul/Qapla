#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define DEBUGTAG 0

int main ()
{
   struct S {
      struct S *parent;
      int x ;
   };

   struct S *s = malloc(sizeof(struct S));
   s->x = 34 ;
   printf("%d\n", s->parent==NULL);

   struct S *t = malloc(sizeof(struct S));
   t->parent = s;
   //s = NULL;
   s = t;
   s->x = 35 ;

   printf("%d\n",s->x);
   printf("%d\n",s->parent->x);

   struct S *tmp = s->parent;
   s->parent = NULL;
   free(s);
   s = NULL;
   s = tmp;
   tmp = NULL;
   printf("%d\n",s->x);
   

   free(s);
  // free(s->parent);
}
