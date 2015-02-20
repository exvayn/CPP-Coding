//удалить повторяющиеся пробелы
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

int main(void)
{
setlocale(0,"RUS");
   char s[100]="";
   int i,j;
   j=0;
   fgets(s,100,stdin);
   for(i=0;i<strlen(s);i++){
    if (s[i+1]!=' ') {s[j]=s[i]; j++;}
     else if (s[i]!=' ') { s[j]=s[i]; j++;}
   }
 s[j]='\0';
   printf("Новая строка: %s", s);
   getch();
}
