#include <stdio.h>
#include <iostream>

void main()
{
  int n,m,i,j,num,p;
  scanf("%d",&n); // ����������� ������� �� ��������� (����� ������)

  // ����������� ������� �� ����������� (����� �������)
  m=n;  // ��� ���������� ������� (����������� ��� ��������������)
  // scanf("%d",&m); // ��� �������������� ������� (������������)

  int** A = new int*[n];                       // ���������� ����������
  for (i = 0; i < n; i++) A[i] = new int [m];  // ������������� ������� 

  // float *A = new int[n]; ���������� ����������� ������������� �������

  p=n/2;

  num=1;

  for(i=0;i<p;i++) //���� �� ������ �����
  {
    for (j=i;j<m-i;j++) A[i][j]=num++;  //����������� �������� �������� ��� ������� 
    for (j=i+1;j<n-i-1;j++) A[j][m-i-1]=num++;  // �� ������� ������������� �������
    for (j=m-i-1;j>=i;--j) A[n-i-1][j]=num++;  // �� ������� ��������������� ������� 
    for (j=n-i-2;j>i;j--) A[j][i]=num++;  // �� ������ ������������� �������
  }
  if (n%2!=0)
  {
    for (i=p;i<m-p;i++)
    A[p][i]=num++;
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++) printf(" %4d ",A[i][j]); // " %4d " �������� �� "%d"  ���� ����
    printf("\n");
  } 
  for (i=0;i<n;i++) delete [] A[i]; //������������ ������ ������������� 2-������� �������
  // delete [] A;        ������������ ������ ������������� ����������� �������
  system("pause");
}