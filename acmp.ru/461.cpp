#include <stdio.h>
FILE *f;
void main(){
	int k,h,d,s,i,j,A[1000];
	f=fopen("input.txt","r");
	fscanf(f,"%d",&k);
	for (i=0;i<k;i++) fscanf(f,"%d",&A[i]);
	fclose(f);
	h=((int) k/2)+1;
	s=0;
	for (i=0;i<k;i++)
		for (j=i+1;j<k;j++)
			if (A[i]>A[j]) {d=A[i]; A[i]=A[j]; A[j]=d;}
	for (i=0;i<h;i++)
	s=s+((int) A[i]/2)+1;
	f=fopen("output.txt","w");
	fprintf(f,"%d",s);
	fclose(f);
}