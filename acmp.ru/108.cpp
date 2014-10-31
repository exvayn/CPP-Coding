#include <stdio.h>
FILE *f;
void main(){
	int x,y;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&x);
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%d",x);
	fclose(f);
}