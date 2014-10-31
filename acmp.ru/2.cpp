#include <stdio.h>
FILE *f;
void main(){
	int n,x=0;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);
	fclose(f);
	if (n>1)
	{
		x=(n*(n+1))/2;		
	} 
	if (n<0) 
	{
		x=-(n*(n-1))/2+1;
	}
	if (n==0) x=1;
	if (n==1) x=1;
	f=fopen("output.txt","w");
	fprintf(f,"%d",x);
	fclose(f);
}
/* через цикл
#include <stdio.h>
FILE *f;
void main(){
	int n,x=0;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);
	fclose(f);
	if (n>0) for (int i=1;i<=n;i++) x+=i;
	else for (int i=1;i>=n;i--) x+=i;
	f=fopen("output.txt","w");
	fprintf(f,"%d",x);
	fclose(f);
}
*/