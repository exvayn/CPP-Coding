#include<iostream>
#include<string.h>
#include<locale.h>
#include<iomanip>
#include <algorithm>
using namespace std;

class discipline{
	public:
	int mount; //����� �����
	char *form_control; //����� ��������
	char *name; //�������� ����������
	discipline()
		{ 
			mount=0; 
			form_control=new char;
			name=new char;
			cout<<"Constructor work!"<<endl;
		}
};
bool cmp(const discipline &a, const discipline &b){
	return a.mount<b.mount;
};
discipline obj[5];

void change(discipline &a, int mt, char *fc, char *nm){
a.mount = mt;
a.form_control = new char[strlen(fc)+1];
	strcpy(a.form_control,fc);
a.name = new char[strlen(nm)+1];
	strcpy(a.name,nm);
}

void sort(){//����������� ����������
	/*int i,j;
	discipline temp;
	for (i=0; i<5; i++)
		for (j=i+1; j<5; j++)
			if (obj[i].mount >obj[j].mount) {
				temp = obj[i];
				obj[i] = obj[j];
				obj[j] = temp;
			}*/
	sort(obj, obj + 5, cmp);
}

void show(){
	int i,j;
	cout<<"                         ����������: \n";
	cout<<"------------------------------------------------------------\n";
	cout<<"   ��������           ����� �����            ����� ��������\n";
	cout<<"------------------------------------------------------------\n";

	char s[10];
	for (i=0; i<5; i++){
		cout<<setw(19) <<obj[i].name;
		cout<<setw(15) <<obj[i].mount;
		cout<<"   "<<setw(20) <<obj[i].form_control;
		cout<<"\n";
	}
	cout<<"----------------------------------------------------------------\n";
}

void main(){
	setlocale(LC_ALL, "rus");
	int r = 0;
	for (int a=0; !a;){
		cout<<"1. �������� ������\n"  ;
		cout<<"2. ����������� ����\n";
		cout<<"3. ������� ����\n";
		cout<<"4. �����\n";
		cout<<"==> ";
		int p;
		cin>>p;

		switch(p) {
			case 1: {
				change(obj[0],100,"�������","����������������");
				change(obj[1],80,"�����","���. ������");
				change(obj[2],10,"�����","����. ��.");
				change(obj[3],200,"��������","���");
				change(obj[4],122,"����","������ ���������");
				r = 1;
				break;
			}

			case 2: {
				if (r == 0) cout<<"� ���� ��� �������.";
				else if (r == 1) {sort(); cout<<"��������������!";}
				cout<<"\n\n";
				system("pause");
				break;
			}

			case 3:{
				if (r == 0) cout<<"� ���� ��� �������.";
				else if (r == 1) show();
				cout<<"\n\n";
				system("pause");
				break;
			}

			case 4:{
				a=1;
				break;
			}

			default:{
				cout<<"�������� �����";
				cout<<"\n\n";
				system("pause");
				break;
			}
		 }
	}
}
