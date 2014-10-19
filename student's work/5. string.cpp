// Ввести с клавиатуры строку. 
// Поменять в строке порядок символов на обратный
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(void)
{  int i;
   char s[100]="", c;
  fgets(s,100,stdin);
   for (i=0;i<strlen(s)/2;i++) {
   c=s[i];
   s[i]=s[strlen(s)-i-1];
   s[strlen(s)-i-1]= c;
   }
   printf("%s\n", s);
   getch();
   return 0;
}