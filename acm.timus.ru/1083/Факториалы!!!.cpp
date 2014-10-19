#include <stdio.h>
#include <string.h>
#include <iostream>
void main(){
  int i,k,n,h,f,b;
  char s[21]="";
  scanf("%d",&n);
  scanf("%s",&s);
  k=strlen(s);
  b=n; i=1; f=1;
  if (n%k==0) h=k; else h=n%k;
  while (b!=h){
    f=f*b;
	b=n-i*k;
	i++;
  }
  f=f*b;
  printf("%d",f);
  system("pause");
}