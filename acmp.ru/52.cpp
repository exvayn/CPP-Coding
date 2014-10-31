#include <stdio.h>
FILE *f;
void main(){
	int a,b,c;
	char s[7];
	f=fopen("input.txt","r");
	fscanf(f,"%s",&s);
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%s",(((int)s[0]-48)+((int)s[1]-48)+((int)s[2]-48)==((int)s[3]-48)+((int)s[4]-48)+((int)s[5]-48))?"YES":"NO");
	fclose(f);
}