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
#include <windows.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;




class data {
public:
	int d; //����
	int m; //�����
	int y; //���
};

class student {
public:
	char fac; //��������� (1 ������)
	int kurs; //����
	int group; //������
	int num; //����� � �������
};

class exam {
	char disc; //����������
	class data date; //���� 
	class student stud; //������� 
	int rating; //������
public:
	exam(void){ memset(this,0,sizeof(exam)); };
	exam(int i){ memset(this,0,sizeof(exam)); this->rating=5;};
	~exam(void){  };
	inline int show(int i){
		printf ("\n�������� ��� ������� %d:\n", i+1);
		switch (disc)
		{
			case '�': printf ("   ����������: ����������������\n");break;
			case '�': printf ("   ����������: �������\n");break;
			case '�': printf ("   ����������: �������\n");break;
			case '�': printf ("   ����������: ���������\n");break;
		}
		printf ("   ���� ��������: %d.%d.%d \n", date.d, date.m, date.y);
		printf ("   �������:\n");
			switch (stud.fac)
			{
				case '�': printf ("      ���������: �������������\n");break;
				case '�': printf ("      ���������: ������������������\n");break;
				case '�': printf ("      ���������: �����������\n");break;
				case '�': printf ("      ���������: �����������\n");break;
				case '�': printf ("      ���������: �������\n");break;
			}
			printf ("      ����: %d\n", stud.kurs);
			printf ("      ������: %d\n", stud.group);
			printf ("      ����� � �������: %d\n", stud.num);
		printf ("   ������: %d\n", rating);
		return 0;
	};
	inline int set(vector<exam> &v){
		int i,j,k,k1,kv;
		printf ("\n\n���� �������� �� ����������� ���������:\n\n");
		printf ("  ������� ���������� �������� ��������: ");
		cin.clear();
		cin>>kv;
		cout<<"\n\n";
		for (i=0;i<kv;i++) 
		{	
			printf ("\n�������� ����� %d:\n", i+1);
				printf ("   ���������� (�,�,�,�): ");
				getchar();
				scanf ("%c",&disc);
				printf ("   ���� (dd.mm.yyyy): ");
				scanf ( "%d.%d.%d",&date.d, &date.m, &date.y );
				printf ("   ���������� � ��������:\n");
					printf ("      ��������� (�,�,�,�,�): ");
					cin.clear();
					cin>>stud.fac;
					printf ("      ���� (1-5): ");
					scanf ( "%d", &stud.kurs );
					printf ("      ������: ");
					scanf ( "%d", &stud.group );
					printf ("      ����� � �������: ");
					scanf ( "%d", &stud.num );
				printf ("   ������: ");
				scanf ( "%d", &rating );
			v.push_back(*this);
		}
		return 0;
	};
	friend int rrr(vector<exam> &v);
	int what_date(int year, int month=-1,int day=-1){
		int a=0;
		if (year!=-1 && month!=-1 && day!=-1){
			if(date.y==year && date.m==month && date.d==day) a=1;
		} else if (year!=-1 && month!=-1){
			if(date.y==year && date.m==month) a=1;
		} else{
			if(date.y==year) a=1;
		}
		return a;
	}
	int what_fac(char facult){
		if(stud.fac==facult) return 1;
		return 0;
	}
	int what_disc(char discc){
		if(disc==discc) return 1;
		return 0;
	}
	int what_kurs(char kuurs){
		if(stud.kurs==kuurs) return 1;
		return 0;
	}
	int what_rating(int stat, char operand='='){
		int a=0;
		if (operand=='>'){
			if(rating>stat) a=1;
		} else if (operand=='<'){
			if(rating<stat) a=1;
		} else if(rating==stat) a=1;
		return a;
	}






	void set_disc(char discc);
	void set_date(int year,int month,int day);
	void set_st_fac(char st_fac);
	void set_st_kurs(char st_kurs);
	void set_st_group(int st_group);
	void set_st_num(int st_num);
	void set_rating(int stat);
};
void exam::set_disc(char discc){
	disc=discc;
}
void exam::set_date(int year, int month, int day){
	date.d=day; date.m=month; date.y=year;
}
void exam::set_st_fac(char st_fac){
	stud.fac=st_fac;
}
void exam::set_st_kurs(char st_kurs){
	stud.kurs=st_kurs;
}
void exam::set_st_group(int st_group){
	stud.group=st_group;
}
void exam::set_st_num(int st_num){
	stud.num=st_num;
}
void exam::set_rating(int stat){
	rating=stat;
}
// �������
int menu(void);
int qqq(vector<exam> &v); //read
int www(vector<exam> &v); //add
int eee(vector<exam> &v); //new
int rrr(vector<exam> &v); //info
int ttt(vector<exam> &v); //������������

char ch='e';
int main(void)
{
	SetConsoleCP(1251);// �������� ������ ��������� ��� ������ �����
	SetConsoleOutputCP(1251); // �������� ������ ��������� ��� ������ ������
	vector <exam> v;
	exam ex;
	ifstream fin("exvayn.san");
	if (fin)
		while(!fin.eof())
			if(fin.read((char *) &ex, sizeof(exam))) v.push_back(ex); 
			else break;
	while (ch!='x'){
		system("cls");
		cout<<"     <<����>>\n";
		cout<<"�������� ������ - 'q'\n";
		cout<<"��������� ������ - 'w' ( ������� ����� - 'e' )\n";
		cout<<"������������ �������������� - 't'\n";
		cout<<"�������������� �������� - 'r'\n";
		cout<<"����� - 'x'\n\n";
		cout<<"����: ";
		cin.clear();
		cin>>ch;
		if (ch=='q') qqq(v); //��������
		else if (ch=='w') www(v); //����������
		else if (ch=='e') eee(v); //�����
		else if (ch=='r') rrr(v); //��� ���� (�� �������) 
		else if (ch=='t') ttt(v); //������������
		else if (ch=='x'){
			ofstream fout("exvayn.san");
			for(int i=0; i<v.size(); i++)
				fout.write((char *) &v[i], sizeof(exam));
		}
		else cout<<"\n�������� ����";
	}
	cout<<"\n\n"; 
	
	
	system("pause");
	return 0;
}

int ttt(vector<exam> &v)
{
	char ch2='s',ac;
	int i=-1,a1,a2,a3;
	while (i!=0){
		system("cls");
		cout<<"������� ����� �������� ( 0 - ����� � ����): ";
		cin>>i;
		if (i>0){
			cout<<"  <<�������� ���� ��� ��������������>>\n";
			cout<<"���������� - 'd'\n";
			cout<<"���� - 't'\n";
			cout<<"������ - 'r'\n";
			cout<<"�������� � ��������\n";
			cout<<"   ��������� - 'f'\n";
			cout<<"   ���� - 'k'\n";
			cout<<"   ������ - 'g'\n";
			cout<<"   ����� � ������� - 'n'\n\n";
			cout<<"����: ";
			cin.clear();
			cin>>ch2;
			cout<<"\n\n������� ����� ������:";
			switch(ch2){
				case 'd': cin>>ac; v[i-1].set_disc(ac); break;
				case 't': scanf ( "%d.%d.%d",&a1, &a2, &a3 ); v[i-1].set_date(a3,a2,a1); break;
				case 'r': cin>>a1; v[i-1].set_rating(a1); break;
				case 'f': cin>>ac; v[i-1].set_st_fac(ac); break;
				case 'k': cin>>a1; v[i-1].set_st_kurs(a1); break;
				case 'g': cin>>a1; v[i-1].set_st_group(a1); break;
				case 'n': cin>>a1; v[i-1].set_st_num(a1); break;
			}
		}
	}
	return 0;
}

int eee(vector<exam> &v)
{
	exam ex;
	v.clear();
	ex.set(v);
	printf("������ ���������.");
	cout<<"\n\n";
	system("pause");
	return 0;
}
int qqq(vector<exam> &v){
	int i,j,kv=v.size();
    printf ("\n\n�������� �� ���������:\n");
    for (i=0;i<kv;i++) v[i].show(i);
	if (kv==0) cout<<"    ��� ��������";
	cout<<"\n\n";
	system("pause");
	return 0;
}
int rrr(vector<exam> &v){
	int i,j,kv=v.size(),k=0;
	
	printf("\n\n�������������� ��������:\n\n");
	printf("    ���������� ������������ �� ���������������� �� \n");
	printf("    ������������� ���������� ����� ��������� ������� �����,\n");
	printf("    ��������� �������� ����� 2012 ����,\n");
	printf("    ������� �� ����� �� ������ � ����� � �������.\n\n");
	for (i=0;i<kv;i++) {
		if ((v[i].what_date(2012,12) || v[i].what_date(2012,1) || v[i].what_date(2012,2)) && v[i].what_fac('�') && v[i].what_kurs(1) && v[i].what_disc('�') && v[i].what_rating(3,'<')){
			printf("%d)������: %d\n",++k,v[i].stud.group);
			printf("    ����� � �������: %d\n\n",v[i].stud.num);
		}
	}
	printf(" ���������� ������������ ��������: %d\n\n",k);
	cout<<"\n";
	system("pause");
	return 0;
}

int www(vector<exam> &v){
	exam ex;
	ex.set(v);
	printf("������ ���������.");
	cout<<"\n\n";
	system("pause");
	return 0;
}
