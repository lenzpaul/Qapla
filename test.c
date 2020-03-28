#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void move();

void test();
void removeChar(char *str, char garbage);
void noEscChar(char *str);
int main()
{

   const char * str = "\"abcd\"\\ef\"";
	//printf("%s\n", str);
	char garbage = '\\';
   noEscChar(str);
	//printf("%s\n", str);
}


void noEscChar(const char *str){
	char *tmp = calloc(strlen(str), sizeof(char));
   int i,j;
   for(i = j = 0; str[i] != '\0'; i++){
      tmp[j] = str[i];
      printf("%c\n", tmp[j]);
      if(tmp[j] != '\\') j++;
	}
   tmp[j] = '\0';
   str = strcpy(*tmp);
   free(tmp);
   

   printf("%s", tmp);
   //*str = *tmp;
   //free(tmp);
   //*str = strdup(*tmp);
}




int b()
{
	//remove quotes
   char * str = "\"abcd\"\\ef\"";
	str = strdup(str+1);
	str[strlen(str)-1] = '\0';

	char* newStr = calloc(strlen(str), sizeof(char));
	while(*str != '\0')
	{
		*newStr = *str;
		if(*newStr != '\\') newStr++;
		str++;
	}
	*newStr = '\0';
	printf("%s\n", str);
\
	//int slen = strlen(str);
	//printf("%d", slen);
	//slen = strlen(str);
	//printf("%d", slen);
	


	printf("%s\n", newStr);
   //move();
   //test();
}


void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}


void test()
{
  char str[] = "memmove can be very useful......";
  printf("%s \n", str+15);
  memmove(str+20,str+15,11);
  puts (str);

}

void move()
{
   char * str = "\"ab\"\\ef\"";
   //char * str = "Hello";
   size_t slen = strlen(str) -2 ;
	//printf("%d\n",slen);
   memmove(str+0,  str+1, slen);
	printf("%s",str);
   str[slen] = '\0';
   printf("%s",str);
}

int copy()
{
   char * str = "\"abcdef\"";
   char * str1 = calloc(strlen(str)-1, sizeof(char));
   strncpy(str1, &str[1], strlen(str)-2);
   str1[strlen(str)-2] = '\0';
   printf("%s \n", str1);
}
