#include <stdio.h>
FILE *f;
void main(){
	int a,b;
	f=fopen("input.txt","r");
	fscanf(f,"%d %d",&a,&b);
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%c",(a>b)?'>':(a<b)?'<':'=');
	fclose(f);
}