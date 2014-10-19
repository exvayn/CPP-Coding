#include <stdio.h>
#include <string.h>
#include <iostream>
void main(void)
{ 
	int n,n1,r,i,j;
	char s[30]="",s1;
	scanf("%d",&n);
	n1=n; j=0;
	if (n>9) {
	while (n1>1){
		r=1;
		for (i=9;i>1;i--) if (n1%i==0) {n1=n1/i; s[j]=i+'0'; r=0; j++; break;}
		if (r) {s[0]='-'; s[1]='1';s[2]='\0'; break;}
	}
	for (i=0;i<strlen(s);i++)
		for (j=i+1;j<strlen(s);j++)
			if ((int) s[i]>(int) s[j]) {s1=s[i];s[i]=s[j]; s[j]=s1;} 
	} else{
	if (n==0) {s[0]='1'; s[1]='0';} 
	else s[0]=n+'0';
	}
	printf("%s\n",s);
	system("pause");
}