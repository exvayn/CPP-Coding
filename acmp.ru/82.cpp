#include <stdio.h>
FILE *f;
void main(){
	int n,m,i,j,k,h,A[100000];
	for (i=0;i<100000;i++) A[i]=0;
	f=fopen("input.txt","r");
	fscanf(f,"%d %d",&n,&m);	
	for (i=0;i<n;i++) {fscanf(f,"%d",&h); A[h]=1;}
	for (i=0;i<m;i++) {fscanf(f,"%d",&h); if (A[h]==1) A[h]=2;}
	fclose(f);
	f=fopen("output.txt","w");
	for (i=0;i<100000;i++) if (A[i]==2) fprintf(f,"%d ",i);
	fclose(f);
}