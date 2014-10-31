#include <stdio.h>
FILE *f;
void main(){
	int x,y;
	f=fopen("input.txt","r");
	fscanf(f,"%d %d",&x,&y);
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%d",x+y);
	fclose(f);
}