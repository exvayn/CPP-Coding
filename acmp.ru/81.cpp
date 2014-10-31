#include <stdio.h>
FILE *f;
void main(){
	int x,n,a,b;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);
	for (int i=1;i<=n;i++){
		fscanf(f,"%d",&x);		
		if (i==1) {a=b=x;}
		else { 
			if (a>x) a=x;
			if (b<x) b=x;
		}
		
	}
	fclose(f);
	f=fopen("output.txt","w");
	fprintf(f,"%d %d",a,b);
	fclose(f);
}