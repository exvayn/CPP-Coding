// �������� ����� ��������� ��� �������� �������
// � ������� ����� ��������� ��� ������ �������
#include <stdio.h>
#include <locale.h>
#include <conio.h>

int main(void)
{
setlocale(0,"RUS");
int m, k, n, i, f;
printf ("������� ���-�� ��-���: ");
scanf("%d",&n);
for (i=1;i<=n;i++) {
printf ("������� %d-�� �������: ", i);
scanf("%d",&f);
if (i<3) { if (i==1) m=f; else k=f;}
else{
if (i%2==0) {if (k>f) k=f;}
else {if (m<f) m=f;}
}
}

printf ("\n �������� ����� ��������: %d ", m);
printf ("\n ������� ����� ������: %d", k);
getch();
return(0);
}