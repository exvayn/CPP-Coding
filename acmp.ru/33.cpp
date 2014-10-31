#include <stdio.h>
FILE *f;
void main(){
	int a,b;
	f=fopen("input.txt","r");
	fscanf(f,"%d %d",&a,&b);
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%d %d",b-1,a-1);
	fclose(f);
}