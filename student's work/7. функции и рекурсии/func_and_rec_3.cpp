//3. ����������� ��������� ����������� ����������� ������ �������� (���) 
//   ���� �����, ��������� �������� �������. 
#include <stdio.h>
#include <conio.h>
#include <iostream>

int function(int a, int b);
void main(void)
{ 
	setlocale(0,"RUS");
	int a,b,s;
	printf("������� a b: ");
	scanf("%d %d", &a, &b);
	s=function(a, b);
	printf("��� = %d \n", s);	
    system("pause");
}
int function(int a, int b)
{
	int c;
	while (b)
	{
	c=b;
	b=a%b;
	a=c;
	}
    return(a);
}
