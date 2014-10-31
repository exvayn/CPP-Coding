#include <stdio.h>
#include <math.h>
FILE *f;
void main(){
	int x,n,a=0,b=0;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);
	for (int i=1;i<=n;i++){
		fscanf(f,"%d",&x);
		if (x==1) b++; else a++;
	}
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%d",(a>b)?b:a);
	fclose(f);
}