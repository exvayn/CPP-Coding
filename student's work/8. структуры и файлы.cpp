/*
2.	�������� �� �������� �������� ��������� ������: 
���������� (����������������, �������, �������, ���������), 
���� ����� �������� (���, �����, ����), 
�������� � �������� (���������, ����, ������, ����� � �������) 
� ��������������� ������. 

����� ����� �������� �� ���������, ������� ���������� �� ��������� ��� ����; 
� ��� ��������� � ������� ���������� ������� ������� ��������. 
���������� ���������� ������������ �� ���������������� �� �������������  
���������� ����� ��������� ������� �����, ��������� �������� ����� 2012 ����, 
������� �� ����� �� ������ � ����� � �������.

����������:
�������������
������������������
�����������
�����������
�������

*/
#include <stdio.h>
//#include <locale.h>
#include <windows.h>
#include <iostream>

	FILE *f;
	struct data {
		int d; //����
		int m; //�����
		int y; //���
	};
	struct student {
		char fac; //��������� (1 ������)
		int kurs; //����
		int group; //������
		int num; //����� � �������
	};

	struct exam {
		char disc; //���������� (1 ������)
		struct data date; //���� (�� �������� ����)
		struct student stud; //������� (�� ������ �������)
		int rating; //������
	};
	struct exam record[1000];

// �������
int menu(void);
int qqq(void); //read
int www(void); //add
int eee(void); //new
int rrr(void); //info
int lobby(void);

int buf=0;

void main(void)
{
	//setlocale(0,"RUS");
	SetConsoleCP(1251);// �������� ������ ��������� ��� ������ �����
	SetConsoleOutputCP(1251); // �������� ������ ��������� ��� ������ ������
	menu();
}
int menu()
{
	char ch;
	system("cls");
	printf("     <<����>>\n"); 
	printf("�������� ������ - 'q'\n");
	printf("��������� ������ - 'w' ( ������� ����� - 'e' )\n");
	printf("�������������� �������� - 'r'\n");
	printf("����� - 'x'\n\n");
	printf("����: ");
	if (buf) getchar();
	scanf ( "%c", &ch );
	buf=1;
	if (ch=='q') {  qqq(); return 0;} //��������
	if (ch=='w') {  www(); return 0;} //����������
	if (ch=='e') {  eee(); return 0;} //�����
	if (ch=='r') {  rrr(); return 0;} //��� ���� (�� �������)
	if (ch=='x') { printf("\n"); system("pause"); return 0;} 
	return 0;
}
int lobby()
{
	char ch;
	printf("\n\n� ���� - 'm' | ����� - 'x'\n\n"); 
	printf("����: ");
	getchar();
	scanf ( "%c", &ch );
	if (ch=='x') {  printf("\n"); system("pause"); return (0);} //�����
	if (ch=='m') {  system("pause"); menu();  return (0);} //� ����
	return 0;
}
int eee()
{
	int i,j,k,k1,kv;
	if((f=fopen("exvayn.kun", "w"))==NULL) 
	{
		printf("������ ��� �������� �����.\n");
		lobby();
		return 0;
	}
	
	printf ("���� �������� �� ����������� ���������:\n");
	printf ("������� ���������� �������� ��������: ");
	scanf("%d",&kv);
	printf ("\n\n");
	for (i=0;i<kv;i++) 
	{	
		printf ("\n�������� ����� %d:\n", i+1);
			printf ("   ���������� (�,�,�,�): ");
			getchar();
			scanf ("%c",&record[i].disc);
			printf ("   ���� (dd.mm.yyyy): ");
			scanf ( "%d.%d.%d", &record[i].date.d, &record[i].date.m, &record[i].date.y );
			printf ("   ���������� � ��������:\n");
				printf ("      ��������� (�,�,�,�,�): ");
				getchar();
				scanf ( "%c", &record[i].stud.fac );
				printf ("      ���� (1-5): ");
				scanf ( "%d", &record[i].stud.kurs );
				printf ("      ������: ");
				scanf ( "%d", &record[i].stud.group );
				printf ("      ����� � �������: ");
				scanf ( "%d", &record[i].stud.num );
			printf ("   ������: ");
			scanf ( "%d", &record[i].rating );
	}

	for(i=0; i<kv; i++)
		if(record[i].disc)
			if(fwrite(&record[i],sizeof(struct exam), 1, f)!=1)  
				printf("������ ��� ������ �����.\n");
	fclose(f);
	printf("������ ������� � ��������� � ����.\n");
	lobby();
	return 0;
}
int qqq(){
	int i,j,kv=-1;
	if((f=fopen("exvayn.kun", "r"))==NULL) 
	{
		printf("������ ��� �������� �����.\n");
		lobby();
		return 0;
	}
	while(true)
		if(fread(&record[++kv],sizeof(struct exam), 1, f)!=1) 
		{
			if (feof(f)) break;
			printf("������ ��� ������ �����.\n");
			fclose(f);
			lobby();
			return 0;
		}
    printf ("\n\n�������� �� ���������:\n");
    for (i=0;i<kv;i++) 
	{

		printf ("\n�������� ��� ������� %d:\n", i+1);
		switch (record[i].disc)
		{
			case '�': printf ("   ����������: ����������������\n");break;
			case '�': printf ("   ����������: �������\n");break;
			case '�': printf ("   ����������: �������\n");break;
			case '�': printf ("   ����������: ���������\n");break;
		}
		printf ("   ���� ��������: %d.%d.%d \n", record[i].date.d, record[i].date.m, record[i].date.y);
		printf ("   �������:\n");
			switch (record[i].stud.fac)
			{
				case '�': printf ("   ���������: �������������\n");break;
				case '�': printf ("   ���������: ������������������\n");break;
				case '�': printf ("   ���������: �����������\n");break;
				case '�': printf ("   ���������: �����������\n");break;
				case '�': printf ("   ���������: �������\n");break;
			}
			printf ("      ����: %d\n", record[i].stud.kurs);
			printf ("      ������: %d\n", record[i].stud.group);
			printf ("      ����� � �������: %d\n", record[i].stud.num);
		printf ("   ������: %d\n", record[i].rating);
    } 
printf ("\n  ����� �����.  \n");
fclose(f);
system("pause");
lobby();
return 0;
}
int rrr(){
	int i,j,kv=-1,k=0;
	if((f=fopen("exvayn.kun", "r"))==NULL) 
	{
		printf("������ ��� �������� �����.\n");
		lobby();
		return 0;
	}
	while(true)
		if(fread(&record[++kv],sizeof(struct exam), 1, f)!=1) 
		{
			if (feof(f)) break;
			printf("������ ��� ������ �����.\n");
			fclose(f);
			lobby();
			return 0;
		}
	printf("\n\n�������������� ��������:\n\n");
	printf("    ���������� ������������ �� ���������������� �� \n");
	printf("    ������������� ���������� ����� ��������� ������� �����,\n");
	printf("    ��������� �������� ����� 2012 ����,\n");
	printf("    ������� �� ����� �� ������ � ����� � �������.\n\n");
	for (i=0;i<kv;i++){
		if (record[i].disc=='�' && record[i].rating<3 && record[i].stud.fac=='�' && record[i].stud.kurs==1 && record[i].date.y==2012 && (record[i].date.m>11 || record[i].date.m<3)){
			printf("%d)������: %d\n",++k,record[i].stud.group);
			printf("    ����� � �������: %d\n\n",record[i].stud.num);
		}	
	}
	printf(" ���������� ������������ ��������: %d\n\n",k);
	fclose(f);
	system("pause");
	lobby(); 
	return (0);
}
int www(){
	int i,j,k,k1,kv;
	if((f=fopen("exvayn.kun", "a"))==NULL) 
	{
		printf("������ ��� �������� �����.\n");
		lobby();
		return 0;
	}
	fseek(f, 0, 2);
	printf ("���������� �������� �� ����������� ���������:\n");
	printf ("������� ���������� �������� ��������: ");
	scanf("%d",&kv);
	printf ("\n\n");
	for (i=0;i<kv;i++) 
	{	
		printf ("\n�������� ����� %d:\n", i+1);
			printf ("   ���������� (�,�,�,�): ");
			getchar();
			scanf ("%c",&record[i].disc);
			printf ("   ���� (dd.mm.yyyy): ");
			scanf ( "%d.%d.%d", &record[i].date.d, &record[i].date.m, &record[i].date.y );
			printf ("   ���������� � ��������:\n");
				printf ("      ��������� (�,�,�,�,�): ");
				getchar();
				scanf ( "%c", &record[i].stud.fac );
				printf ("      ���� (1-5): ");
				scanf ( "%d", &record[i].stud.kurs );
				printf ("      ������: ");
				scanf ( "%d", &record[i].stud.group );
				printf ("      ����� � �������: ");
				scanf ( "%d", &record[i].stud.num );
			printf ("   ������: ");
			scanf ( "%d", &record[i].rating );
	}

	for(i=0; i<kv; i++)
		if(record[i].disc)
			if(fwrite(&record[i],sizeof(struct exam), 1, f)!=1)  
				printf("������ ��� ������ �����.\n");
	fclose(f);
	printf("������ ������� � ��������� � ����.\n");
	lobby();
	return 0;
}
