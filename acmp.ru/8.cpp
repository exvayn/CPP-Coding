#include <stdio.h>
FILE *f;
void main(){
	int a,b,c;
	f=fopen("input.txt","r");
	fscanf(f,"%d %d %d",&a,&b,&c);
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%s",(a*b==c)?"YES":"NO");
	fclose(f);
}