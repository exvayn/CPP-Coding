#include <stdio.h>
#include <iostream>

void main()
{
  int n,i,j,num,p,k,n1;
  scanf("%d",&n);
  int** A = new int*[n];                       
  for (i = 0; i < n; i++) A[i] = new int [n];  
  p=n-1;
  num=1;
  if (n%2==0) {n1=n*2;} else {n1=n*2-1;}
  for(k=0;k<n1;k++) 
  { for (i=0;i<n;i++)
	 for (j=0;j<n;j++)
		 if (j-i==p) {A[i][j]=num; num++;}
	p--;
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++) printf("%d ",A[i][j]);
    printf("\n");
  } 
  for (i=0;i<n;i++) delete [] A[i];
  system("pause");
}