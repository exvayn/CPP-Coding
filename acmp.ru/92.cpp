#include <stdio.h>
FILE *f;
void main(){
	int x;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&x);
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%d9%d",x,9-x);
	fclose(f);
}