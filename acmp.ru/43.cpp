#include <stdio.h>
#include <string.h>
FILE *f;
void main(){
	char s[101];
	int i,k,k1;
	f=fopen("input.txt","r");
	fscanf(f,"%s",&s);
	fclose(f);

	k=k1=0;
	for (i=0;i<strlen(s);i++){
		if (s[i]=='0') {k1++; if (i==strlen(s)-1 && k<k1) k=k1;}
		else {if (k<k1) k=k1; k1=0;}
	}

	f=fopen("output.txt","w");
	fprintf(f,"%d",k);
	fclose(f);
}