#include <stdio.h>
#include <iostream>

void main()
{
  int n,i,j,k,p,n1;
  scanf("%d",&n);
  int** A = new int*[n];                       
  for (i = 0; i < n; i++) A[i] = new int [n]; 
  for (i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&A[i][j]);

  p=0;
  if (n%2==0) {n1=n*2;} else {n1=n*2-1;}
  for(k=0;k<n1;k++) 
  { for (i=n-1;i>=0;i--)
	 for (j=0;j<n;j++)
		 if (j+i==p) printf("%d ",A[i][j]);
	p++;
  }
  for (i=0;i<n;i++) delete [] A[i];
  system("pause");
}