//2. �������� �������, ������� ����������
//   ����������� ������� ����������� �������.
#include <stdio.h>
#include <conio.h>
#include <iostream>

int function(int mass[10]);
void main(void)
{ 
	setlocale(0,"RUS");
	int mas[10],i,min;
	printf("������� ������ �� 10 ���������. \n");
	for (i=0;i<10;i++) scanf("%d", &mas[i]);
    min=function(mas);
	printf("���. ��.: %d \n", min);
	system("pause");
}
int function(int mass[10])
{
	int min,j;
	min=mass[0];
	for (j=1;j<10;j++)
	if (min>mass[j]) min=mass[j];
    return(min);
}
