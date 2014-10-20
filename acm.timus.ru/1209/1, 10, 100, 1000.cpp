#include <stdio.h>
#include <math.h>
#include <iostream>
// ������� ����� n ����� s=(n*(n+1))/2 - n ����� �������� ��-�� ������������������
// ������� ������������������ ������ ������ ������ k=(n*(n+1))/2+1 - n ����� ������� ������� ������������������
// ��� ���
// ������������������ s = 3 6 10 15 21
// ������������������ k = 4 7 11 16 22
// 
// ���� ��������� ����� �� n. ���� ����� �� ������ ������� ��� ������� k �������� ������ ������������������ ������ ����� 0
// �� �������� k-1=(n(n+1))/2
//             2k-2=n(n+1)
//             -n^2-n+2k-2=0
//             n^2+n-2k+2=0 - �������� ������� (��� a=1, b=1, c=-2k+2)
//
//  D = b^2-4*a*c = 1-4(-2k+2) = 1+8k-8 = 8k-7
//
// n1=(-b-sqrt(D))/(2*a)   n2=(-b+sqrt(D))/(2*a)
// n1=(-1-sqrt(8k-7)/2 n1=(-1+sqrt(8k-7)/2
// ��� ���� ��� �� n ���� ����� ���� ���� � ����������� ���� ������ (��� ����� �� 2) � ����� (��� �������) ����� 
// ��� ���� ����� � ����������� ���� ������ � ����� ����� ���� ���� sqrt(8k-7) ��� �������� (��� �������� ��� ���������� � ��������� 1 - ����� ������) � ����� (��� ����� �������)
// ��!!! 8k-7 �� ������ ���� �������� (��� 8k - ����� k ������� ������, � -7 ��������� ��� ������ � ��������)
// ���� ������ ����� �����, �� ��� ��������� ����� ��� ������ ����� �������� (sqrt(9)=3; sqrt(25)=5 � ��) ������ ������� ��� ��� �������� ������ ��������� sqrt(8k-7) �� ��������!
//
// ����� ���� ��� ���������� � ��������� n1=(-1-sqrt(8k-7)/2 ��� n2=(-b+sqrt(D))/(2*a) �� �����
// p.s. ����� k ��� ��� ������ � int � float
// Ho 8*k y}I{e HeT
void main(void)
{
	int f,k,n;
	scanf("%d",&n);
	int*A=new int[n];
	for (f=0;f<n;f++) scanf("%d",&A[f]);
	for (f=0;f<n;f++){
		k=A[f];
		if (sqrt((double)8*k-7)==(int)(sqrt((double)8*k-7))) printf("1 ");
		else printf("0 ");
	}
		system("pause");
}

/*
//������� ����� ���� (timelimit �� timus-�)
void main(void)
{
	int i,f,j,k,n;
	scanf("%d",&n);
	int*A=new int[n];
	for (f=0;f<n;f++) scanf("%d",&A[f]);
	for (f=0;f<n;f++){
		k=A[f];
		i=j=1;
		while (i+j<=k && k!=1){
		i=i+j;
		j++;
		}
		if (i==k) printf("1 ");
		else printf("0 ");
	}
	
		system("pause");
}
*/