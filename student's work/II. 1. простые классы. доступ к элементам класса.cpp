#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>

class antelopes{
	char name[8];
	char group;
	char place[14];
	int nums;
	public:
		antelopes(){name[0]='\0'; place[0]='\0';}
		void set(char *s1, char s2, char *s3, int s4);
		void show();
};
void antelopes::set(char *s1, char s2, char *s3, int s4){
	strcpy(name,s1); group=s2; strcpy(place,s3); nums=s4;
}
void antelopes::show(){
	printf("| %8s |    %c   | %14s | %21d |\n",name,group,place,nums);
}
int show(antelopes *x){
	printf("|------------------------------------------------------------|\n");
	printf("| ��������� ���� �������                                     |\n");
	printf("|------------------------------------------------------------|\n");
	printf("| �������� | ������ | ����� �������� | ����������� ��������� |\n");
	printf("|------------------------------------------------------------|\n");
	for (int i=0;i<3;i++) x[i].show();
	printf("|------------------------------------------------------------|\n");
	printf("| ������: � - ��������� ��������, B - ������� ��������,      |\n");
	printf("| H - ��������� ��������                                     |\n");
	printf("|------------------------------------------------------------|\n");
	return 0;
}
int main(){
	SetConsoleCP(1251);// �������� ������ ��������� ��� ������ �����
	SetConsoleOutputCP(1251); // �������� ������ ��������� ��� ������ ������
	antelopes *x = new antelopes[3]; 
	int i;
	/* 
	std::string s1,s3; char s2; int s4;
	//���� �� ����
	for (i=0;i<=2;i++){
		std::cout<<"���� ���� "<<i+1<<") \n";
		std::cout<<"   ���: ";      std::cin>>s1; 
		std::cout<<"   ������: ";      std::cin>>s2; 
		std::cout<<"   ����� ��������: ";      std::cin>>s3; 
		std::cout<<"   ���������: ";      std::cin>>s4;
		x[i].set(s1,s2,s3,s4);
	}
	*/
	x[0].set("�������",'�',"����",30000);
	x[1].set("���",'�',"������",560000);
	x[2].set("�����",'�',"������",2500);
	show(x);
	system("pause");
	return 0;
}