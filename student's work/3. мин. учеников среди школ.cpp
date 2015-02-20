//ввести количество учащихся N, учавствующих в олимпиаде
//в следующих N строчках ввести для каждого ученика:
//<Фамилию (<=20 символов)> <Инициалы (4 символа [буква точка буква точка])> <Номер школы (не более 2значного номера)> 
//Найти школы отправившие наименьшее количество участников.
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

int main(void)
{
setlocale(0,"RUS");
   int a[100];
   char str1[21], str2[5];
   int i,sNum,N,min;
    for(i=0;i<100;i++){
     a[i]=0;
    }
	printf("Ввести кол-во учеников на олимпиаде: ");
    scanf("%d",&N);
   for (i=1;i<N+1;i++){
	printf("Информация об %d-ом ученике: ", i);
      scanf("%s %s %d",str1,str2,&sNum);
      a[sNum]=a[sNum]+1;
  }
   min=N;
   for(i=1;i<100;i++){
     if(a[i]>0){
       if(a[i]<min)  min=a[i];
     }
   }
printf("Номера школ с минимальным кол-вом учеников на олимпиаде:");
   for(i=1;i<100;i++){
     if (a[i]==min){
       printf("\n - %d",i);
     }
   }
  getch();
}
