/*
2.	Сведения об экзамене содержат следующие данные: 
дисциплину (программирование, алгебра, история, геометрия), 
дату сдачи экзамена (год, месяц, день), 
сведения о студенте (факультет, курс, группа, номер в журнале) 
и экзаменационную оценку. 

Задан набор сведений об экзаменах, сданных студентами за последние два года; 
в них факультет и предмет кодируются первыми буквами названия. 
Определить количество неуспевающих по программированию на экономическом  
факультете среди студентов первого курса, сдававших экзамены зимой 2012 года, 
вывести на экран их группу и номер в журнале.

Факультеты:
Экономический
Машиносторительный
Юридический
Технический
Пищевой
*/

#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;




class data {
public:
	int d; //день
	int m; //месяц
	int y; //год
};

class student {
public:
	char fac; //факультет (1 символ)
	int kurs; //курс
	int group; //группа
	int num; //номер в журнале
};

class exam {
	char disc; //дисциплина
	class data date; //дата 
	class student stud; //студент 
	int rating; //оценка
public:
	exam(void){ memset(this,0,sizeof(exam)); };
	exam(int i){ memset(this,0,sizeof(exam)); this->rating=5;};
	~exam(void){  };
	inline int show(int i){
		printf ("\nСведения под номером %d:\n", i+1);
		switch (disc)
		{
			case 'П': printf ("   Дисциплина: Программирование\n");break;
			case 'А': printf ("   Дисциплина: Алгебра\n");break;
			case 'И': printf ("   Дисциплина: История\n");break;
			case 'Г': printf ("   Дисциплина: Геометрия\n");break;
		}
		printf ("   Дата рождения: %d.%d.%d \n", date.d, date.m, date.y);
		printf ("   Студент:\n");
			switch (stud.fac)
			{
				case 'Э': printf ("      Факультет: Экономический\n");break;
				case 'М': printf ("      Факультет: Машиносторительный\n");break;
				case 'Ю': printf ("      Факультет: Юридический\n");break;
				case 'Т': printf ("      Факультет: Технический\n");break;
				case 'П': printf ("      Факультет: Пищевой\n");break;
			}
			printf ("      Курс: %d\n", stud.kurs);
			printf ("      Группа: %d\n", stud.group);
			printf ("      Номер в журнале: %d\n", stud.num);
		printf ("   Оценка: %d\n", rating);
		return 0;
	};
	inline int set(vector<exam> &v){
		int i,j,k,k1,kv;
		printf ("\n\nВвод сведений об резальтатах экзаменов:\n\n");
		printf ("  Введите количество вводимых сведений: ");
		cin.clear();
		cin>>kv;
		cout<<"\n\n";
		for (i=0;i<kv;i++) 
		{	
			printf ("\nСведения номер %d:\n", i+1);
				printf ("   Дисциплина (П,А,И,Г): ");
				getchar();
				scanf ("%c",&disc);
				printf ("   Дата (dd.mm.yyyy): ");
				scanf ( "%d.%d.%d",&date.d, &date.m, &date.y );
				printf ("   Информация о студенте:\n");
					printf ("      Факультет (Э,М,Ю,Т,П): ");
					cin.clear();
					cin>>stud.fac;
					printf ("      Курс (1-5): ");
					scanf ( "%d", &stud.kurs );
					printf ("      Группа: ");
					scanf ( "%d", &stud.group );
					printf ("      Номер в журнале: ");
					scanf ( "%d", &stud.num );
				printf ("   Оценка: ");
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
// функции
int menu(void);
int qqq(vector<exam> &v); //read
int www(vector<exam> &v); //add
int eee(vector<exam> &v); //new
int rrr(vector<exam> &v); //info
int ttt(vector<exam> &v); //поэлементное

char ch='e';
int main(void)
{
	SetConsoleCP(1251);// включаем нужные кодировки для потока ввода
	SetConsoleOutputCP(1251); // включаем нужные кодировки для потока вывода
	vector <exam> v;
	exam ex;
	ifstream fin("exvayn.san");
	if (fin)
		while(!fin.eof())
			if(fin.read((char *) &ex, sizeof(exam))) v.push_back(ex); 
			else break;
	while (ch!='x'){
		system("cls");
		cout<<"     <<Меню>>\n";
		cout<<"Просмотр данных - 'q'\n";
		cout<<"Дополнить данные - 'w' ( Создать новые - 'e' )\n";
		cout<<"Поэлементное редактирование - 't'\n";
		cout<<"Дополнительные сведения - 'r'\n";
		cout<<"Выйти - 'x'\n\n";
		cout<<"Ввод: ";
		cin.clear();
		cin>>ch;
		if (ch=='q') qqq(v); //просмотр
		else if (ch=='w') www(v); //дополнение
		else if (ch=='e') eee(v); //новый
		else if (ch=='r') rrr(v); //доп свед (по заданию) 
		else if (ch=='t') ttt(v); //поэлементное
		else if (ch=='x'){
			ofstream fout("exvayn.san");
			for(int i=0; i<v.size(); i++)
				fout.write((char *) &v[i], sizeof(exam));
		}
		else cout<<"\nневерный ввод";
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
		cout<<"Введите номер сведений ( 0 - выход в меню): ";
		cin>>i;
		if (i>0){
			cout<<"  <<Выберите поле для редактирования>>\n";
			cout<<"Дисциплина - 'd'\n";
			cout<<"Дата - 't'\n";
			cout<<"Оценка - 'r'\n";
			cout<<"Сведения о студенте\n";
			cout<<"   Факультет - 'f'\n";
			cout<<"   Курс - 'k'\n";
			cout<<"   Группа - 'g'\n";
			cout<<"   Номер в журнале - 'n'\n\n";
			cout<<"Ввод: ";
			cin.clear();
			cin>>ch2;
			cout<<"\n\nВведите новые данные:";
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
	printf("Данные сохранены.");
	cout<<"\n\n";
	system("pause");
	return 0;
}
int qqq(vector<exam> &v){
	int i,j,kv=v.size();
    printf ("\n\nСведения об экзаменах:\n");
    for (i=0;i<kv;i++) v[i].show(i);
	if (kv==0) cout<<"    нет сведений";
	cout<<"\n\n";
	system("pause");
	return 0;
}
int rrr(vector<exam> &v){
	int i,j,kv=v.size(),k=0;
	
	printf("\n\nДополнительные сведения:\n\n");
	printf("    Количество неуспевающих по программированию на \n");
	printf("    экономическом факультете среди студентов первого курса,\n");
	printf("    сдававших экзамены зимой 2012 года,\n");
	printf("    вывести на экран их группу и номер в журнале.\n\n");
	for (i=0;i<kv;i++) {
		if ((v[i].what_date(2012,12) || v[i].what_date(2012,1) || v[i].what_date(2012,2)) && v[i].what_fac('Э') && v[i].what_kurs(1) && v[i].what_disc('П') && v[i].what_rating(3,'<')){
			printf("%d)Группа: %d\n",++k,v[i].stud.group);
			printf("    Номер в журнале: %d\n\n",v[i].stud.num);
		}
	}
	printf(" Количество неуспевающих учеников: %d\n\n",k);
	cout<<"\n";
	system("pause");
	return 0;
}

int www(vector<exam> &v){
	exam ex;
	ex.set(v);
	printf("Данные сохранены.");
	cout<<"\n\n";
	system("pause");
	return 0;
}
